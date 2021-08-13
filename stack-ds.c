#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0;

typedef struct Stack
{
	int items[MAX];
	int top;
} stack;

void createEmptyStack(stack *pstk)
{
	pstk->top = -1;
}

int isFull(stack *pstk)
{
	if (pstk->top == MAX - 1)
		return 1;
	else
		return 0;
}

int isEmpty(stack *pstk)
{
	if (pstk->top == -1)
		return 1;
	else
		return 0;
}

void push(stack *pstk, int newitem)
{
	if (isFull(pstk))
		printf("\nStack is Full!\n");
	else
	{
		pstk->top++;
		pstk->items[pstk->top] = newitem;
		count++;
	}
}

void pop(stack *pstk)
{
	if (isEmpty(pstk))
		printf("\nStack empty!\n");
	else
	{
		printf("\nItem popped = %d\n", pstk->items[pstk->top]);
		pstk->top--;
		count--;
	}
}

void printStack(stack *pstk)
{
	printf("\nStack: ");

	for (int i = 0; i < count; i++)
	{
		printf("%d ", pstk->items[i]);
	}

	printf("\n");
}

int main()
{
	stack *pstk = (stack *)malloc(sizeof(stack));

	createEmptyStack(pstk);

	pop(pstk);

	push(pstk, 1);
	push(pstk, 2);
	push(pstk, 3);
	push(pstk, 4);

	printStack(pstk);

	pop(pstk);

	printf("\nAfter popping out");
	printStack(pstk);

	push(pstk, 6);

	printf("\nAfter pushing up");
	printStack(pstk);

	return 0;
}