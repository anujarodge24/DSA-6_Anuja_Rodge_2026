

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, value;
    
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) 
    {
        printf("\nMemory allocation failed!");
        return 1;
    }

    printf("\nEnter %d unique elements:", n);

    for (i = 0; i < n; i++) 
    {
        scanf("%d", &value);


        int isDuplicate = 0;
        for (j = 0; j < i; j++) 
        {
            if (arr[j] == value) 
            {
                isDuplicate =1;
                break;
            }
        }

        if (isDuplicate) 
        {
            printf("Duplicate element!Enter a different value:\n");
            i--; 
            
        } else 
        {
            arr[i] = value;
        }
    }

    printf("\nArray elements:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    free(arr); 
    return 0;
}


