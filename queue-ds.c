#include <stdio.h>

#define SIZE 5

void enqueue(int);
void dequeue();
void display();

int items[SIZE], front = -1, rear = -1;

int main()
{
	dequeue();

	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);

	enqueue(6);

	display();

	dequeue();

	display();

	return 0;
}

void enqueue(int value)
{
	if (rear == SIZE - 1)
		printf("\nQueue is Full!\n");
	else
	{
		if (front == -1)
			front = 0;

		rear++;
		items[rear] = value;
		printf("\nInserted -> %d\n", value);
	}
}

void dequeue()
{
	if (front == -1)
		printf("\nQueue is Empty!\n");
	else
	{
		printf("\nDeleted: %d\n", items[front]);
		front++;

		if (front > rear)
			front = rear = -1;
	}
}

void display()
{
	if (rear == -1)
		printf("\nQueue is Empty!\n");
	else
	{
		printf("\nQueue elements are: ");

		for (int i = front; i < rear; i++)
			printf("%d ", items[i]);

		printf("\n");
	}
}