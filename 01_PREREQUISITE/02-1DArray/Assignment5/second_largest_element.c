#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//function declarations
int* inputArray(int size);
int second_large(int* arr , int size);

int main(void)
{
    int size = 0;
    printf("\nEnter size: ");
    scanf("%d" , &size);

    int* arr = inputArray(size);

    int second = second_large(arr, size);
    printf("\nSecond Largest Element:%d", second);

    return 0;

}

int* inputArray(int size)
{
	
	int* arr = (int*)malloc(sizeof(int) * size);
	if(arr == NULL)
	{
		printf("out of memory");
		return NULL;
	}

	printf("\nEnter Array Element: ");
	for(int i = 0; i < size ; i++)
	{
		scanf("%d" , (arr+i));
	}

	return arr;

}

int second_large(int* arr, int n)
{
    int second = INT_MIN , large = INT_MIN;

    for(int i = 0; i < n ; i++)
    {
        if(arr[i] > large)
        {
            second = large;
            large = arr[i];
        }

        else if(arr[i] > second && arr[i] < large)
        {
            second = arr[i];
        }

    }

    return second;
}