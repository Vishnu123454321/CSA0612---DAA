#include <stdio.h>
#include <limits.h> 
void printSum(int result[], int front, int tail)
{
	printf("[");
	for (int i = front; i < tail; ++i)
	{
		if (result[i] != INT_MAX)
		{
			printf(" %d ", result[i]);
		}
	}
	printf("]\n");
}
void subsetSum(int arr[], int result[], int sum, int size, int current_sum, int location)
{
	if (location == -1)
	{
		return;
	}
	subsetSum(arr, result, sum, size, current_sum, location - 1);
	
	result[location] = arr[location];
	if (current_sum + arr[location] == sum)
	{
		printSum(result, location, size);
	}
	subsetSum(arr, result, sum, size, current_sum + arr[location], location - 1);
	result[location] = INT_MAX;
}
void findSubset(int arr[], int size, int sum)
{
	if (size <= 0)
	{
		return;
	}
	int result[size];
	for (int i = 0; i < size; ++i)
	{
		result[i] = INT_MAX;
	}
	printf("Subser Sum of %d is \n", sum);
	subsetSum(arr, result, sum, size, 0, size - 1);
}
int main()
{
	int arr[] = {
		6 , -3 , 8 , 2 , 1 , 4 , 3
	};
	int size = sizeof(arr) / sizeof(arr[0]);
	int sum = 10;
	findSubset(arr, size, sum);
	return 0;
}
