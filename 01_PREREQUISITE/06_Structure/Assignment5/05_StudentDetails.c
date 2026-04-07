/*
    Create a structure "Students" with below member variables:
	- Name of student,
    - Roll no. Of Student,
    - array of 5 Subject marks,
	- Total Percentage 
    
- Calculate the Percentage for "N" number of students,
- Display all details for all students,
- Display the details of topper.
(use array of structure)
*/

#include<stdio.h>

typedef struct Students
{
	char name[20];
	int rollno;
	int marks[5];
	float percent;
}stud;

int main(void)
{
	
	int students = 0;
	printf("Enter no of Students:");
	scanf("%d",&students);
	
	int total =0;
	
	stud s[students];
	
	for(int i =0; i<students; i++)
	{
		total = 0;
		
		printf("\nEnter Details of %d th Students:",i+1);
		
		printf("\nName:");
		scanf(" %[^\n]",s[i].name);
		
		printf("\nRoll No:");
		scanf("%d", &s[i].rollno);
		
		//Enter 5 subjects Marks
		
		printf("\nEnter 5 Subjects Marks:");
		for(int j =0 ; j<5; j++)
		{
			scanf("%d", &s[i].marks[j]);
			total = total + s[i].marks[j];
		}
		
		s[i].percent = (total/500.0)*100;
	}
	
	stud topper = s[0];
	
	for(int i =0 ; i<students ; i++)
	{
		if(topper.percent < s[i].percent)
		{
			topper = s[i];
		}
	}
	
	//Display All Details For All Students
	
	printf("\n\nAll Students Details:\n");
	for(int i =0; i<students ; i++)
	{
		printf("\nName:%s",s[i].name);
		printf("\nRollNo:%d",s[i].rollno);
        
		printf("\nMarks: ");
        for (int j = 0; j < 5; j++)
            printf("%d ", s[i].marks[j]);

        printf("\nPercentage:%.2f", s[i].percent);
	}

		
	//Display Topper Details
	printf("\n\n****Topper Student****\n");
	printf("\nName:%s", topper.name);
	printf("\nRoll No:%d",topper.rollno);
	printf("\nPercentage:%.2f", topper.percent);
	
	return 0;
}
	
	
	
	
	