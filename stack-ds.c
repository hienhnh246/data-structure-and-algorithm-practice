#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0;

typedef struct Stack
{
	int items[MAX];
	int top;
} stack;

void createEmptyStack(stack *sp)
{
	sp->top = -1;
}

int isFull(stack *sp)
{
	if (sp->top == MAX - 1)
		return 1;
	else
		return 0;
}

int isEmpty(stack *sp)
{
	if (sp->top == -1)
		return 1;
	else
		return 0;
}

void push(stack *sp, int newitem)
{
	if (isFull(sp))
		printf("\nStack full!\n");
	else
	{
		sp->top++;
		sp->items[sp->top] = newitem;
		count++;
	}
}

void pop(stack *sp)
{
	if (isEmpty(sp))
		printf("\nStack empty!\n");
	else
	{
		printf("\nItem popped = %d\n", sp->items[sp->top]);
		sp->top--;
		count--;
	}
}

void printStack(stack *sp)
{
	printf("\nStack: ");

	for (int i = 0; i < count; i++)
	{
		printf("%d ", sp->items[i]);
	}

	printf("\n");
}

int main()
{
	stack *sp = (stack *)malloc(sizeof(stack));

	createEmptyStack(sp);

	pop(sp);

	push(sp, 1);
	push(sp, 2);
	push(sp, 3);
	push(sp, 4);

	printStack(sp);

	pop(sp);

	printf("\nAfter popping out");
	printStack(sp);

	push(sp, 6);

	printf("\nAfter pushing up");
	printStack(sp);

	return 0;
}