#include <stdio.h>

int iterativeBinarySearch(int array[], int x, int low, int high)
{
	while (low <= high)
	{
		int mid = (low + (high - low)) / 2;

		if (array[mid] == x)
			return mid;
		if (array[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}

int recursiveBinarySearch(int array[], int x, int low, int high)
{
	if (low <= high)
	{
		int mid = (low + (high - low)) / 2;

		if (array[mid] == x)
			return mid;
		if (array[mid] < x)
			return recursiveBinarySearch(array, x, mid + 1, high);
		else
			return recursiveBinarySearch(array, x, low, mid - 1);
	}

	return -1;
}

int main()
{
	int array[] = {3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(array) / sizeof(array[0]);
	int x = 4;
	int result1 = iterativeBinarySearch(array, x, 0, size - 1);
	int result2 = recursiveBinarySearch(array, x, 0, size - 1);

	if (result1 == -1 && result2 == -1)
		printf("Not found");
	else
		printf("Element is found at index %d & %d\n", result1, result2);

	return 0;
}