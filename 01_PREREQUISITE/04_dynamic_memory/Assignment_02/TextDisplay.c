/*
-write a C program to input and print text using Dynamic Memory Allocation.
- create memory for text string at run time using malloc() function, 
- text string will be inputted by the user and displayed.
- Using free() function  release the occupied memory.
*/

#include<stdio.h>
#include<stdlib.h>

//function declaration
char* inputString();

int main(void)
{
    char* string = inputString();

    if(string != NULL)
    {
        printf("\nstring:%s", string);

    }

    free(string);

    return 0;
    

}

char* inputString()
{
    int size = 100;

    //allocate memory
    char* str = (char*)malloc(sizeof(char)*size);
    if(str == NULL)
    {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }

    printf("Enter Text: ");
    fgets(str , size , stdin);

    return str;

}

