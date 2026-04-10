#include <stdio.h>

//function declarations
void revertArray(int arr[], int size);
void printArray(int arr[], int size);

int main() 
{
    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements: ");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array: ");
    printArray(arr, size);

    //=============calling to revert function====================
    revertArray(arr, size);

    printf("\nReverted Array: ");
    printArray(arr, size);

    return 0;
}

void revertArray(int arr[], int size)
{
    int temp;
    
    for (int i = 0; i < size / 2; i++) 
    {
        temp = arr[i];
        arr[i] = arr[size - 1 -i];
        arr[size -1 - i] = temp;
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0;i < size;i++) 
    {
        printf(" %d ",arr[i]);
    }
}