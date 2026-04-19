#include <stdio.h>
#include <string.h>

int length(char str[]) 
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int main() 
{
    char str[100];

    printf("enter a string:");
    fgets(str, sizeof(str), stdin); 

    str[strcspn(str, "\n")] = '\0';

    int len = length(str);
    printf("length of the string = %d\n", len);

    return 0;
}
