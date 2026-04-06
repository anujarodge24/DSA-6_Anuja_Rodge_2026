/*
 write a C program to read and print the N student details using structure and Dynamic Memory Allocation.
    - create a structure with N number of student details and print the inputted details. 
	- Memory to store and print structure will be allocated at run time by using malloc() and released by free().

*/

#include <stdio.h>
#include <stdlib.h>

//Structure define
typedef struct Student
{
    int ID;
    char name[50];
    float marks;

}stud;

//Function declarations
stud* createStructure(int n);
void displayDetails(stud* s, int n);


int main(void)
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    //==========Input function calling =============
    stud* s = createStructure(n);

    //=========output function calling============
    displayDetails(s, n);

    free(s);
    s = NULL;

    return 0;
}

stud* createStructure(int n)
{
    stud* s1 = (stud*)malloc(sizeof(stud)* n);
    if(s1 == NULL)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }
    
    for(int i = 0; i < n ; i++)
    {
        printf("\nEnter student ID: ");
        scanf("%d", &s1[i].ID);

   
        while (getchar() != '\n'); 

        printf("Enter student Name: ");
        fgets(s1[i].name, sizeof(s1[i].name), stdin);
    
        printf("Enter student marks: ");
        scanf("%f", &s1[i].marks);

    }
    

    return s1;

}

void displayDetails(stud* s, int n) 
{
    if (s == NULL) 
        return;

    printf("\n*********** Student Details ************\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("\n\nDetails of student %d ", i+1);
        printf("\nstudent ID    :%d", s[i].ID);
        printf("\nstudent Name  :%s", s[i].name);
        printf("student marks :%0.2f", s[i].marks);

    }
    
}

