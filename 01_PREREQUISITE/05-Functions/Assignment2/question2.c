//Write a function to find the length of a string.


#include <stdio.h>

//function declaration
int stringLength(char* str );

int main(void)
{
    char str[100];

    printf("Enter String: ");
    fgets(str, sizeof(str), stdin); 


    //function calling
    int length = stringLength(str);
    printf("\nLength of String: %d " , length);

    return 0;
}

//function defination
int stringLength(char* str)
{
    int length = 0;
    for( int i = 0 ; str[i] != '\0' ; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||  (str[i] >= 'a' && str[i] <= 'z'))
            length++;
    }
    return length;
}