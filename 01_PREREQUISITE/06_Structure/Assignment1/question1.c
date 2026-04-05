/* ->Write a C program to create , declare and initialise structure.
-> define a structure "Student", which includes the details of students.
->declare an object of the structure and initialise the structure members.*/

#include<stdio.h>
#include<string.h>

//structure creation
typedef struct student 
{
    char name[50];
    int id;
    float marks;
    char grade;
}student;

int main(void)
{
    student stud;

    //structure initialise
    strcpy(stud.name, "Anuja");
    stud.id = 12;
    stud.marks = 98.99f;
    stud.grade = 'O';

    //Printing
    printf("\n------Student Record--------");
    printf("\nName:%s", stud.name);
    printf("\nRoll_no:%d", stud.id);
    printf("\nMarks:%f", stud.marks);
    printf("\nGrade:%c", stud.grade);

    return 0;
}