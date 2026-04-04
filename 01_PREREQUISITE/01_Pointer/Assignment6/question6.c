//Write a function which reads pointers of 2 different arrat as arguments, return the pointer of array which elements are sum of two array elements.

#include <stdio.h>

//function declaration
void arraySum(int* ptr_arr1 , int* ptr_arr2 , int* ptr_arrsum , int size);


int main(void)
{
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5] = { 60, 70, 80, 90, 100};
    int arr_sum[5];

    //function calling
    arraySum(arr1, arr2, arr_sum,  5);

    printf("\nSum of two array elements: ");
    for(int i = 0 ; i <5 ; i++)
    {
        printf("\nSum of %d th elements of array : %d " , (i+1) , arr_sum[i]);
    }

    return 0;


}

void arraySum(int* ptr_arr1 , int* ptr_arr2 , int* ptr_arrsum, int size)
{

    for(int i = 0; i < size ; i++)
    {
        ptr_arrsum[i] = *(ptr_arr1 + i) + *(ptr_arr2 + i);

    }

}