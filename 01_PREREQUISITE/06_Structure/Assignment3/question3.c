/*Write a C Program which demonstrate a nested structure.
->define a structure employee inside a structure person.
->structure person data: Name, Age, Date of birth, blood group.
->structure employee data: Company name, Emp id, salary, year of experience
->create object of structure of structure and disply all deatails of a person.*/

#include <stdio.h>
#include <string.h>

typedef struct Employee
{
    char companyName[50]; 
    int empID;
    float salary;
    int year_of_experience;
}employee;

typedef struct Person
{
    char name[50];
    int age;
    
    struct Date{
        int day, month, year;
    } dob;
    char blood_group[5];  
    employee emp;        
} person;

//function declaration
void displayDetails(person p);


int main() {
    
    person p;

    //Initialisation
    strcpy(p.name, "Anuja");
    p.age = 21;
    p.dob.day = 7;
    p.dob.month = 4;
    p.dob.year = 2004;
    strcpy(p.blood_group, "O+");
    strcpy(p.emp.companyName , "Infosys");
    p.emp.salary = 98000.80;
    p.emp.year_of_experience = 4;


    displayDetails(p);

    return 0;
}

void displayDetails(person p) 
{
    printf("\n*************Employee Details**************\n");
    printf("\nEmployee Name      : %s" , p.name);
    printf("\nEmployee Age       : %d",  p.age);
    printf("\nBlood Group        : %s\n", p.blood_group);
    printf("DOB                : %d/%d/%d", p.dob.day, p.dob.month, p.dob.year);
    printf("\nCompany Name       : %s", p.emp.companyName);
    printf("\nEmployee ID        : %d", p.emp.empID);
    printf("\nEmployee Salary    : %.2f", p.emp.salary);
    printf("\nEmployee Experience: %d Years", p.emp.year_of_experience);
}
