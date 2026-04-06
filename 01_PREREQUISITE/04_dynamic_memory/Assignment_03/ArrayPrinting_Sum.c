/*
   write a C program to read a one dimensional array, print sum of all elements along with inputted array elements using Dynamic Memory Allocation.
   - allocate memory for one dimensional array and print the array elements along with sum of all elements. 
   - Memory will be allocated in this program using malloc() and released using free().

*/

#include <stdio.h>
#include <stdlib.h>

//Function declarations
int* inputArray(int n);
int arraySum(int* arr, int n);
void display(int* arr, int n);



int main(void)
{
    int size = 0;
    printf("\nEnter Array size: ");
    scanf("%d", &size);

    //function calling
    int* arr = inputArray(size);

    printf("\nInput Array Printing: ");
    display(arr , size);

    int sum = arraySum(arr , size);
    printf("\nSum of Array:%d" , sum);

    free(arr);
    arr = NULL;

    return 0;

}


int* inputArray(int n)
{
    //Memory allocation for array
    int* arr = (int*)malloc(sizeof(int) * n);
    if(arr == NULL)
    {
        puts("out of memory");
        exit (EXIT_FAILURE);
    }

    printf("\nEnter array elements: ");
    for(int i = 0; i < n ; i++)
    {
        scanf(" %d", &arr[i]);
    }

    return arr;
}

int arraySum(int* arr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        
    }

    return sum;
}

void display(int* arr, int n)
{
    for(int i = 0; i < n ; i++)
    {
        printf(" %d", arr[i]);
    }
}

