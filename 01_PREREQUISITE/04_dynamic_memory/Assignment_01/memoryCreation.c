/*
- write a C program to create memory for int, char and float variable at run time.
- create memory for int, char and float variables at run time using malloc() function
- and before exiting the program release the memory allocated at run time by using free() function
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Declare pointers
    char* cptr = NULL;
    int* iptr = NULL;
    float* fptr = NULL;

     //===========Memory Allocation==========
    
     //Memory Creation for character
    cptr = (char*)malloc(sizeof(char));
    
    //Memory Creation for integer
    iptr = (int*)malloc(sizeof(int));

    //Memory creation for float
    fptr = (float*)malloc(sizeof(float));

    //Memory allocation checking
    if(cptr == NULL || iptr == NULL || fptr == NULL)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    //Assign values for pointer
    *cptr = 'c';
    *iptr = 10;
    *fptr = 23.9f;

    //=============Display============
    printf("\ncharacter: %c", *cptr);
    printf("\nInteger: %d", *iptr);
    printf("\nfloat: %0.2f", *fptr);

    //==========Free allocated memory=======
    free(cptr);
    free(iptr);
    free(fptr);

    cptr = NULL;
    iptr = NULL;
    fptr = NULL;

    return 0;

}