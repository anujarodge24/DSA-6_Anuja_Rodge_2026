//write a program to print a string using pointer..

#include<stdio.h>

int main(void)
{
    char str[50];
       
    printf("Enter String: ");
    gets(str);

    char* pstr = str;

    printf("\nString Printing: ");

    for(int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", *(pstr+i));
    }

    return 0;

}