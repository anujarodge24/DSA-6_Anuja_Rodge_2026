//write a program to read array element and print with address

#include<stdio.h>

int main(void)
{
    int arr[50];
    int size = 0;
    
    printf("\nEnter size: ");
    scanf("%d", &size);

    //declare integer pointer
    int* ptr = arr;
    
    //Input 
    puts("*****************************************");
    printf("\nEnter array elements: ");
    for(int i = 0; i < size ; i++)
    {
        scanf("%d" , &arr[i]);
    }
    
    //Printing array element with address
    puts("***********************************************");
    printf("\nArray element with address:\n ");
    for(int i = 0; i < size ; i++)
    {
        printf("\n%d with address %p.", *(ptr+i), (ptr+i) );
    }

    return 0;

}