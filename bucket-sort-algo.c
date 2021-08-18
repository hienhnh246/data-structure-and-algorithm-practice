#include <stdio.h>
#include <stdlib.h>

#define NARRAY 7    // Array size
#define NBUCKET 6   // Number of buckets
#define INTERVAL 10 // Each bucket capacity

struct node
{
	int data;
	struct node *next;
};

int getBucketIndex(int value)
{
	return value / INTERVAL;
}

struct node *insertionSort(struct node *list)
{
	struct node *k, *nodeList;

	if (list == 0 || list->next == 0)
		return list;

	nodeList = list;
	k = list->next;
	nodeList->next = 0;

	while (k != 0)
	{
		struct node *ptr;

		if (nodeList->data > k->data)
		{
			struct node *tmp;
			tmp = k;
			k = k->next;
			tmp->next = nodeList;
			nodeList = tmp;
			continue;
		}

		for (ptr = nodeList; ptr->next != 0; ptr = ptr->next)
		{
			if (ptr->next->data > k->data)
				break;
		}

		if (ptr->next != 0)
		{
			struct node *tmp;
			tmp = k;
			k = k->next;
			tmp->next = ptr->next;
			ptr->next = tmp;
			continue;
		}
		else
		{
			ptr->next = k;
			k = k->next;
			ptr->next->next = 0;
			continue;
		}
	}

	return nodeList;
}

void printBuckets(struct node *list)
{
	struct node *cur = list;

	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

// Sorting function
void bucketSort(int array[])
{
	int i, j;
	struct node **buckets;

	// Create buckets and allocate memory size
	buckets = (struct node **)malloc(sizeof(struct node *) * NBUCKET);

	// Initialize empty buckets
	for (i = 0; i < NBUCKET; ++i)
		buckets[i] = NULL;

	// Fill the buckets with respective elements
	for (i = 0; i < NARRAY; ++i)
	{
		struct node *current;
		int pos = getBucketIndex(array[i]);
		current = (struct node *)malloc(sizeof(struct node));
		current->data = array[i];
		current->next = buckets[pos];
		buckets[pos] = current;
	}

	// Print the buckets along with their elements
	for (i = 0; i < NBUCKET; ++i)
	{
		printf("Bucket[%d]: ", i);
		printBuckets(buckets[i]);
		printf("\n");
	}

	// Sort the elements of each bucket
	for (i = 0; i < NBUCKET; ++i)
		buckets[i] = insertionSort(buckets[i]);

	printf("-------------\n");
	printf("Bucktets after sorting\n");
	for (i = 0; i < NBUCKET; i++)
	{
		printf("Bucket[%d]: ", i);
		printBuckets(buckets[i]);
		printf("\n");
	}

	// Put sorted elements on array
	for (j = 0, i = 0; i < NBUCKET; ++i)
	{
		struct node *pnode = buckets[i];

		while (pnode)
		{
			array[j++] = pnode->data;
			pnode = pnode->next;
		}
	}
}

void printArray(int array[])
{
	for (int i = 0; i < NARRAY; ++i)
		printf("%d ", array[i]);

	printf("\n");
}

int main()
{
	int array[NARRAY] = {42, 32, 33, 52, 37, 47, 51};

	printf("Initial array: ");
	printArray(array);
	printf("-------------\n");

	bucketSort(array);
	printf("-------------\n");
	printf("Sorted array: ");
	printArray(array);

	return 0;
}