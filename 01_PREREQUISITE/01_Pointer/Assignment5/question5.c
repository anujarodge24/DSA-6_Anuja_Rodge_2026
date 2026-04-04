//Write a Program to print addresses and size of all types of pointer variables..

#include <stdio.h>

int main(void)
{
    int i = 10;
    char ch = 'A';
    float f = 3.14f;
    double d = 2.555;

    int* ptr_to_int = &i;
    char* ptr_to_char = &ch;
    float* ptr_to_float = &f;
    double* ptr_to_double = &d;

    
    printf("\nsizeof(int): %d bytes" , sizeof(int));
    printf("\nAddress of pointer to integer: %p" , (ptr_to_int));
    printf("\nsizeof(ptr_to_int): %d bytes\n" , sizeof(ptr_to_int));

    puts("********************************************************");
    printf("\nsizeof(char): %d byte" , sizeof(char));
    printf("\nAddress of pointer to character: %p" , (ptr_to_char));
    printf("\nsizeof(ptr_to_char): %d bytes\n" , sizeof(ptr_to_char));

    puts("********************************************************");
    printf("\nsizeof(float): %d bytes" , sizeof(float));
    printf("\nAddress of pointer to float: %p" , (ptr_to_float));
    printf("\nsizeof(ptr_to_float): %d bytes\n" , sizeof(ptr_to_float));

    puts("********************************************************");
    printf("\nsizeof(double): %d bytes" , sizeof(double));
    printf("\nAddress of pointer to double: %p" , (ptr_to_double));
    printf("\nsizeof(ptr_to_double): %d bytes\n" , sizeof(ptr_to_double));

    return 0;


}