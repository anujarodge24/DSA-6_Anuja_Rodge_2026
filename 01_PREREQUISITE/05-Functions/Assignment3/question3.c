//Write a separate function to copy one string into another string

#include <stdio.h>

void stringCopied(char* str1 , char* str2);

int main(void)
{
    char str1[100];
    char str2[100];

    printf("Enter String: ");
    fgets(str1, sizeof(str1), stdin);
    
    //function calling
    stringCopied(str1 , str2);
    
    printf("\nCopied String: %s" , str2);
    

    return 0;
}

void stringCopied(char* str1, char* str2)
{
    int i = 0;

    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
}
