#include<stdio.h>
#include<stdlib.h>

//function declaration
int* mergeArray(int* arr1 ,int size1, int* arr2, int size2);
int* inputArray(int size);
void sortArray(int* arr, int size);
void display(int* arr, int n);

int main(void)
{
	int size1 = 0;
	printf("\nEnter size of array1: ");
	scanf("%d" , &size1);
	
	//Array one created
	int* arr1 = inputArray(size1);

	int size2 = 0;
	printf("\nEnter size of array: ");
	scanf("%d" , &size2);
	
	//Array 2 created
	int* arr2 = inputArray(size2);
	
	printf("\nMerged Array: ");
	int* merge = mergeArray( arr1, size1 , arr2, size2);
	display(merge , size1+size2);
 
	printf("\nSort Merge Array: ");
	sortArray(merge, size1+size2);
	display(merge, size1+size2);

	//free memory
	free(arr1);
	free(arr2);
	free(merge);



	return 0;
}

int* inputArray(int size)
{
	
	int* arr = (int*)malloc(sizeof(int) * size);
	if(arr == NULL)
	{
		printf("out of memory");
		return NULL;
	}

	printf("\nEnter Array Element: ");
	for(int i = 0; i < size ; i++)
	{
		scanf("%d" , (arr+i));
	}

	return arr;

}

int* mergeArray(int* arr1 , int size1 , int* arr2, int size2)
{
	int* merge_arr = (int*)malloc(sizeof(int) * (size1+size2));
    if (merge_arr == NULL) 
	{
        printf("Memory allocation failed\n");
        return NULL;
    }

	//copy first array
	for (int i = 0; i < size1 ; i++) 
	{
        merge_arr[i] = arr1[i];
    }

    // Copy second array
    for (int i = 0; i < size2; i++) {
        merge_arr[size1 + i] = arr2[i];
    }

    return merge_arr;
}

void sortArray(int* arr , int n)
{
	for(int i=0; i < n ; i++)
	{
		for(int j=i+1; j < n; j++)
		{
			if(arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
			
	}


}

void display(int* arr, int n)
{
	for(int i = 0; i < n ; i++)
	{
		printf(" %d", *(arr+i));
	}
}



