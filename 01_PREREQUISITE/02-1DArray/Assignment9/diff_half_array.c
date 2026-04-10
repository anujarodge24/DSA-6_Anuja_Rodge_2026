#include <stdio.h>

int main() {
    int size;
    int sum1stHalf = 0, sum2ndHalf = 0;

    printf("Enter size: ");
   scanf("%d", &size);

    int arr[size]; 
    int mid = size / 2;

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    for(int i =0 ; i< size; i++)
    {
        if (i < mid) 
        {
            sum1stHalf += arr[i];
        } 
        else {
            sum2ndHalf += arr[i];
        }
    }

    int diff = sum1stHalf - sum2ndHalf;

    if(diff < 0)
    {
        diff = diff * -1;
    }

    printf("\nSum of 1st half: %d", sum1stHalf);
    printf("\nSum of 2nd half: %d", sum2ndHalf);
    printf("\nDifference: %d\n", diff);

    return 0;
}