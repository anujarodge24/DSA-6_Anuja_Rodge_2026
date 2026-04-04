//Write a Program to count vowels and consonants in String using pointer.

#include<stdio.h>

int main(void)
{
    char str[] = "Hello World";
    char* cptr = str;

    int vowels = 0;
    int consonant = 0;

    while(*cptr != '\0')
    {
        if(*(cptr) >= 'A' && *(cptr) <= 'Z'  || *(cptr) >= 'a' && *(cptr) <= 'z') {
            
            if(*(cptr) == 'a' || *(cptr) == 'e' || *(cptr) == 'i' || *(cptr) == 'o' || *(cptr) == 'u' || *(cptr) == 'A' || *(cptr) == 'E' || *(cptr) == 'I' || *(cptr) == 'O' || *(cptr) == 'U')
                vowels++;

            else
                consonant++;
        }

        cptr++;  // move pointer forward
    }

    printf("\nNumber of Vowels(Hello World):%d", vowels);
    printf("\nNumber of Consonant(HelloWorld):%d", consonant);

    return 0;
    
}