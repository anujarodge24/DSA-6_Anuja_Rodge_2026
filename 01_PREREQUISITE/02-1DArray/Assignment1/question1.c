/* ->Write a C program which allocates an array dynamically.
   ->Implement logic to check the frequency of each element throughout the array. */


#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int size = 0;
    printf("Enter size: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(sizeof(int) * size);
    if(arr == NULL)
    {
        puts("out of memory");
        return EXIT_FAILURE;
    }

    printf("\nEnter array elements: ");
    for(int i = 0; i < size ; i++)
    {
        scanf("%d" , &arr[i]);
    }
    int count = 0;

    printf("\nFrequencies of elements: \n");
    for(int i = 0; i< size ; i++)
    { 
        count = 0;
        for(int j = 0 ; j < size ; j++)
        {
            if(arr[i] == arr[j])
            {
                
                if(j < i)
                  break;

                count++;
            }
        }
        
        if(count != 0)
            printf("\nfrequency of %d is %d", arr[i], count);
    
    }

    free(arr);
    arr = NULL;


}