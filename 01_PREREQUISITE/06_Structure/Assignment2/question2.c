/*->Write a C progran to read and print an employee's detail using structure.
->Read and print the employees detail like name, employee id, salary etc
using structure*/

#include <stdio.h>
#include <string.h>

typedef struct Employee
{
    char name[50];
    int id;
    float salary;
}employee;

//Function declarations
void employee_display(employee *e);

int main(void)
{
    employee emp;

    //Input 
    printf("\nEnter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);

    printf("\nEnter Employee ID:");
    scanf("%d", &emp.id);

    printf("\nEnter Employee salary:");
    scanf("%f", &emp.salary);

    //Function calling
    employee_display(&emp);

    return 0;

}

void employee_display(employee* e)
{
    printf("\n---------Employee Information-----------");
    printf("\nEmployee Name: %s", e->name);
    printf("\nEmployee ID: %d ", e->id);
    printf("\nEmployee Salary:%0.2f", e->salary);

}