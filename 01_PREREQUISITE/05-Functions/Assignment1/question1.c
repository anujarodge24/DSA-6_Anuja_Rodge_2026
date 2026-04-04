//Write a function to calculate the sum of all elements of an array

#include<stdio.h>
#include<stdlib.h>

//function declaration
int arraySum(int* arr, int size);

int main(void)
{
    int size = 0;
    printf("Enter array size: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(sizeof(int) * size);
    if(arr == NULL)
    {
        puts("out of menory");
        return EXIT_FAILURE;
    }

    printf("\nEnter array elements: ");
    for(int i = 0; i < size ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    //function calling
    int sum = arraySum(arr, size);
    printf("Sum of elements in array: %d", sum);

    free(arr);

    return 0;
}

int arraySum(int* arr, int n)
{
    int sum = 0;

    for(int i = 0; i < n ; i++)
    {
        sum = sum + *(arr + i);

    }

    return sum;
}