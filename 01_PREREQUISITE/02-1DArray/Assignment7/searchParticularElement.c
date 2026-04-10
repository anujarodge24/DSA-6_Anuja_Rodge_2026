//Accept n elements in an array and search a perticular element 

#include <stdio.h>

//Function declarations
int findKey(int arr[], int size, int key);
void inputArray(int arr[], int size);


int main() {
    int size, key;

    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size]; 
    inputArray(arr, size);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    int result = findKey(arr, size, key);

    if (result != -1) 
    {
        printf("\n%d found at position %d", key, result + 1);
    } else 
    {
        printf("\nElement not found");
    }

    return 0;
}

int findKey(int arr[], int size, int key) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == key) 
        {
            return i; 
        }
    }
    return -1; 
}
void inputArray(int arr[], int size) 
{
    printf("\nEnter elements: ");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }
}
