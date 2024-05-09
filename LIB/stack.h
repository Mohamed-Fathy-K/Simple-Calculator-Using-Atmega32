#ifndef StackADT_h
#define StackADT_h

/*********************************************************************************/
/****************************** Array-based implementation************************/
/*********************************************************************************/

#define MAXSTACK    20

typedef char StackEntry;

typedef struct stack{
	int top;
	StackEntry entry[MAXSTACK];
} Stack;


/*********************************************************************************/
/*********************************************************************************/
/*********************************************************************************/

void	Push			(StackEntry, Stack *);
void	Pop				(StackEntry *, Stack *);
int		StackEmpty		(Stack *);
int		StackFull		(Stack *);
void	CreateStack		(Stack *);
void	StackTop		(StackEntry *, Stack *);
int		StackSize		(Stack *);
void	ClearStack		(Stack *);
void	TraverseStack	(Stack *, void (*)(StackEntry));


#endif
