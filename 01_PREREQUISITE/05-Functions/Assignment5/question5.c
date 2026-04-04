//Write a function to reverse the string

#include <stdio.h>
#include<string.h>


void stringReverse(char* str);

int main(void)
{
    char str[100];

    printf("Enter String1: ");
    gets(str);

    //function calling
    stringReverse(str);
    
    printf("\nReverse String: %s" , str);
    

    return 0;
}

void stringReverse(char* str)
{
    int length = strlen(str);
    for(int i = 0 ; i < length/2 ; i++)
    {
        char temp = str[i];
       str[i] = str[length - 1 - i] ;
        str[length - 1 - i]  = temp;


    }
}
