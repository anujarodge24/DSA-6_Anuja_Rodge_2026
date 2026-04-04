//Write a Program to read and print student details using structure pointer.

#include <stdio.h>
#include <stdlib.h>

//define structure
struct student{
    int id;
    char name[20];
    float marks;
};

int main(void)
{
    struct student s;      
    struct student *ptr = &s;   


    // Input student details
    printf("Enter ID: ");
    scanf("%d", &ptr->id);

    printf("Enter Name: ");
    scanf(" %[^\n]", ptr->name);  

    printf("Enter Marks: ");
    scanf("%f", &ptr->marks);

    // Display student details
    printf("\nStudent Details:\n");
    printf("ID : %d\n", ptr->id);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %f\n", ptr->marks);

    return 0;
}
    
