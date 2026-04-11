/*/*write a c program to create and display a node. with structure "Student" with following data members:  
Name
Roll no
standard
Division
*/

#include<stdio.h>
#include<stdlib.h>

//define structure
typedef struct student
{
	char name[20];
	int rno;
	int std;
	char div;
	struct student* next;
}stud;
	
//function declarations
stud* create_node();
void display(stud*);


int main(void)
{
	stud* start = NULL;        
	
    //function calling 
    start = create_node();   
	
    display(start);
    
    //free structure pointer and set it to NULL
	free(start);
    start = NULL;
	
	return 0;
}

stud* create_node()
{
	stud* nw  = (stud*)malloc(sizeof(stud));
    if(nw == NULL)
    {
        puts("out of memory");
        exit (EXIT_FAILURE);
    }
		
	printf("\nEnter name:");
	scanf("%s", &nw->name);
	
    printf("\nEnter roll no:");
	scanf("%d", &nw->rno);
	
    printf("\nEnter standard:");
	scanf("%d", &nw->std);
	
    printf("\nEnter division:");
	getchar();                     
    scanf("%c", &nw->div);
	

    nw->next = NULL;
		
    return nw;
}


void display(stud* p)
{
    if( p == NULL)
       return;

    printf("\n-------Student Details----------\n");
	printf("\nName:%s, RollNo: %d , Standard:%d , Division:%c",p->name, p->rno ,  p->std , p->div);
}
