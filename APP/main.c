#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/stack.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../HAL/Keypad/KPD_interface.h"

#include "../HAL/CLCD/CLCD_interface.h"

// Function prototypes
u8 isDigit(char);
u32 operation(char , u32 op1,u32 op2);
u8 precedent(char op1, char op2);
void infixToPostfix(char infix[], char postfix[]);
u32 evaluatePostfix(char expr[]);

// Main function
void main(void)
{
    char Local_charInput, Local_arrLCDString[17], Local_arrPostfix[30];  // Local variables declaration
    u32 Local_u16Result = 0;  // Variable to store the result of the evaluation
    u8 Local_u8flag = 0, Local_u8LCDCursorCounter = 0; // Flags and counters initialization
    Local_arrLCDString[16] = '\0';  // Null-terminate the LCD string

    // Initialization functions
    DIO_enuInit();  // Initialize Digital Input/Output
    CLCD_enuInit(); // Initialize Character LCD

    // Main loop
    while(1)
    {
        // Get the pressed key from the keypad
        Local_charInput  = KPD_u8GetPressedKey();

        // Check if a key is pressed
        if(KPD_NO_KEY_PRESSED != Local_charInput)
        {
            // Check if the pressed key is '='
            if(Local_charInput == '=')
            {
                Local_u8flag = 1; // Set the flag to indicate evaluation
                CLCD_voidSetCursor(0, 1); // Set cursor position on the CLCD

                // Convert infix expression to postfix
                infixToPostfix(Local_arrLCDString, Local_arrPostfix);

                // Evaluate the postfix expression
                Local_u16Result = evaluatePostfix(Local_arrPostfix);

                // Display the result on the CLCD
                CLCD_voidWriteNumber(Local_u16Result);
            }
            // Check if the pressed key is 'O'
            else if(Local_charInput == 'O')
            {
                // Clear the LCD string
                for(Local_u8LCDCursorCounter = 0 ; Local_u8LCDCursorCounter < 16 ; Local_u8LCDCursorCounter++)
                {
                    Local_arrLCDString[Local_u8LCDCursorCounter] = ' ';
                }
                Local_u8LCDCursorCounter = 0;  // Reset cursor counter

                Local_u8flag = 0; // Reset the evaluation flag
                CLCD_enuClear();  // Clear the CLCD
            }
            else
            {
                // Check if evaluation flag is not set
                if(!Local_u8flag)
                {
                    // Write the pressed character on the CLCD
                    CLCD_enuWriteChar(Local_charInput);
                    Local_arrLCDString[Local_u8LCDCursorCounter++] = Local_charInput; // Store the character in the LCD string
                }
                else
                {
                    // Do nothing
                }
            }
        }
        else
        {
            // Do nothing
        }
    }
}

// Function to check if a character is a digit
u8 isDigit(char c)
{
    return c >= '0' && c <= '9'; // Return 1 if the character is a digit, otherwise return 0
}

// Function to perform arithmetic operation
u32 operation(char operation, u32 op1, u32 op2)
{
    switch(operation)
    {
        case '+' : return op1 + op2 ; break;
        case '-' : return op1 - op2 ; break;
        case 'X' : return op1 * op2 ; break;
        case '/' : return op1 / op2 ; break;
    }
    return 0;
}

// Function to check precedence of operators
u8 precedent(char op1, char op2)
{
    if(op1 == '/' || op1 == 'X')
    {
        return 1;
    }
    if(op1 == '+' || op1 == '-')
    {
        return op2 != '/' && op2 != 'X';
    }

    return 1;
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[])
{
    u32 i = 0,j = 0;
    char c, op;
    Stack s;
    CreateStack(&s); // Create stack to store operators

    // Loop through the infix expression
    for(i = 0 ; (c=infix[i])!='\0'; i++)
    {
        if(isDigit(c))
        {
            postfix[j++] = c; // Append digits directly to postfix expression
        }
        else
        {
            postfix[j++] = ' '; // Add space before appending operators
            if(!(StackEmpty(&s)))
            {
                StackTop(&op, &s); // Get top operator from stack
                // Pop operators with higher precedence and append them to postfix expression
                while(!StackEmpty(&s) && precedent(op, c))
                {
                    Pop(&op, &s);
                    postfix[j++] = op;
                    if(!StackEmpty(&s)) StackTop(&op, &s);
                }
            }
            Push(c, &s); // Push current operator to stack
        }
    }
    postfix[j++] = ' '; // Add space at the end of postfix expression
    // Append remaining operators from stack to postfix expression
    while(!StackEmpty(&s))
    {
        Pop(&op, &s);
        postfix[j++] = op;
    }
    postfix[j] = '\0'; // Null-terminate postfix expression
}

// Function to evaluate postfix expression
u32 evaluatePostfix(char expr[])
{
    u32 i = 0,j = 0;
    char c;
    u32 operands[8] = {0}; // Array to store operands
    u32 tempNumber = 0;
    u32 op1 = 0, op2 = 0, res = 0;
    // Loop through the postfix expression
    for(i = 0 ; (c=expr[i])!='\0' ; i++)
    {
        if(isDigit(c))
        {
            tempNumber *= 10;
            tempNumber += c - '0'; // Convert character to integer and update temporary number
        }
        else if(c == ' ')
        {
            operands[j++] = tempNumber; // Store operand in array
            tempNumber = 0; // Reset temporary number
        }
        else
        {
            op2 = operands[--j]; // Pop operands from array
            op1 = operands[--j];
            res = operation(c, op1, op2); // Perform operation
            operands[j++] = res; // Store result in array
        }
    }
    return res; // Return final result
}
