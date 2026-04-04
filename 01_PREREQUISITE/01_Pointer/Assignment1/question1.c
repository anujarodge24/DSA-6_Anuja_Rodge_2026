#include<stdio.h>

//Function declaration
void swap(int*, int*);

int main()
{
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5] = {60, 70, 80, 90, 100};

    puts("***********************************");
    printf("Before Swapping arr1 and arr2: ");
    
    printf("\narr1: ");
    for(int i =0; i<5; i++)
    {
        printf(" %d",arr1[i]);
    }
    
    printf("\narr2: ");
    for(int i =0; i<5; i++)
    {
      
        printf(" %d", arr2[i]);
    }

    printf("\n\n");
    
    swap(arr1, arr2);
    
    
    puts("************************************");
    printf("After Swapping arr1 and arr2: ");
    
    printf("\narr1: ");
    for(int i =0; i<5; i++)
    {
        printf(" %d",arr1[i]);
    }
    
    printf("\narr2: ");
    for(int i =0; i<5; i++)
    {
      
        printf(" %d", arr2[i]);
    }

    return 0;
}

void swap(int* arr1, int* arr2)
{
    int temp;
    
    for(int i =0; i<5 ; i++)
    {
        temp = *(arr1 + i);
        *(arr1 + i) = *(arr2 + i);
        *(arr2 + i) = temp;

    }

}