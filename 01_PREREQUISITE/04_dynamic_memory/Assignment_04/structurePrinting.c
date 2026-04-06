/* 
write a C program to read and print the student details using structure and Dynamic Memory Allocation.
  - create a structure with student details and print the inputted details. 
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
stud* createStructure();
void displayDetails(stud* s);


int main(void)
{
    //==========Input function calling =============
    stud* s = createStructure();

    //=========output function calling============
    displayDetails(s);

    free(s);
    s = NULL;

    return 0;
}

stud* createStructure()
{
    stud* s1 = (stud*)malloc(sizeof(stud));
    if(s1 == NULL)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter student ID: ");
    scanf("%d", &s1->ID);

   
    while (getchar() != '\n'); 

    printf("Enter student Name: ");
    fgets(s1->name, sizeof(s1->name), stdin);
    
    printf("Enter student marks: ");
    scanf("%f", &s1->marks);

    return s1;

}

void displayDetails(stud* s) 
{
    if (s == NULL) 
        return;

    printf("\n*********** Student Details ************");
    printf("\nstudent ID    :%d", s->ID);
    printf("\nstudent Name  :%s", s->name);
    printf("student marks :%0.2f", s->marks);
}

