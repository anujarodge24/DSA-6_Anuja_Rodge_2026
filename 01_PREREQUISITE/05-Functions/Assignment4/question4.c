//Write a function to concatinate two string

#include <stdio.h>

void stringConcat(char* str1 , char* str2 , char* str3);

int main(void)
{
    char str1[100];
    char str2[100];
    char str3[100];

    //String 1 input
    printf("Enter String1: ");
    gets(str1);
    
    //String 2 input
    printf("\nEnter String2: ");
    gets(str2);
    
    //function calling
    stringConcat(str1 , str2, str3);
    
    printf("Concatinated String: %s" , str3);
    

    return 0;
}

void stringConcat(char* str1, char* str2, char* str3)
{
    while (*str1)
    {
        *str3++ = *str1++;
    }

    *str3++ = ' '; 

    while (*str2)
    {
        *str3++ = *str2++;
    }

}

