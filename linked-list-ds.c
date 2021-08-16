#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

void printLinkedList(struct node *pnode)
{
	while (pnode != NULL)
	{
		printf("%d ", pnode->value);
		pnode = pnode->next;
	}
}

int main()
{
	struct node *head,
	    *one = NULL,
	    *two = NULL,
	    *three = NULL;

	one = (struct node *)malloc(sizeof(struct node));
	two = (struct node *)malloc(sizeof(struct node));
	three = (struct node *)malloc(sizeof(struct node));

	one->value = 1;
	two->value = 2;
	three->value = 3;

	one->next = two;
	two->next = three;
	three->next = NULL;

	head = one;

	printLinkedList(head);
	printf("\n");

	return 0;
}