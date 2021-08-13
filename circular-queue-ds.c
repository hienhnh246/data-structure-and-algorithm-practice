#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull()
{
	if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
		return 1;

	return 0;
}

int isEmpty()
{
	if (front == -1)
		return 1;

	return 0;
}

void enQueue(int element)
{
	if (isFull())
		printf("\nQueue is Full!\n");
	else
	{
		if (front == -1)
			front = 0;

		rear = (rear + 1) % SIZE;
		items[rear] = element;
		printf("\nInserted -> %d\n", element);
	}
}

void deQueue()
{
	if (isEmpty())
		printf("\nQueue is Empty!\n");
	else
	{
		printf("\nDeleted element -> %d\n", items[front]);

		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % SIZE;
	}
}

void display()
{
	int i;

	if (isEmpty())
		printf("\nQueue is Empty!\n");
	else
	{
		printf("\nFront -> %d\n", front);
		printf("Items -> ");

		for (i = front; i != rear; i = (i + 1) % SIZE)
			printf("%d ", items[i]);

		printf("%d ", items[i]);
		printf("\nRear -> %d\n", rear);
	}
}

int main()
{
	// Fails because front = -1
	deQueue();

	enQueue(1);
	enQueue(2);
	enQueue(3);
	enQueue(4);
	enQueue(5);

	// Fails to enqueue because front == 0 && rear == SIZE - 1
	enQueue(6);

	display();
	deQueue();

	display();

	enQueue(7);
	display();

	// Fails to enqueue because front == rear + 1
	enQueue(8);

	return 0;
}