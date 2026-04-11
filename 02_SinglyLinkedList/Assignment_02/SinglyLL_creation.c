/*
write a c program to Create and Display Singly Linked list. with structure "Student" with following data members:
Name
Roll no
standard
Division

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	char name[20];
	int rno;
	int std;
	char div;
	struct student* next;
}stud;
	
//function declaration
stud* creation(stud*);
void display(stud*);
void freeList(stud*);

int main(void)
{
	stud* start = NULL;        
	
    start = creation(start);   
	
    display(start);
	
    freeList(start);
	
    return 0;
}

stud* creation(stud* head)
{
	stud* nw = NULL;
	stud* lst = NULL;
	int ans;
	
	do{
		nw = (stud*)malloc(sizeof(stud));
        if(nw == NULL)
        {
            puts("out of memory");
            exit (EXIT_FAILURE);
                
        }
		
		printf("Enter name:");
		scanf("%s",&nw->name);
		
        printf("Enter roll no:");
		scanf("%d",&nw->rno);
	    
        printf("Enter standard:");
		scanf("%d",&nw->std);
	    
        printf("Enter division:");
		getchar();
		scanf("%c",&nw->div);
		
        nw->next = NULL;
		
		if (head == NULL) {
            head = nw;
        } else {
            lst->next = nw;
        }
        lst = nw;

        printf("\nDo you want to enter new record? (1/0): ");
        scanf("%d", &ans);

    } while(ans == 1);

    return head;
}


void display(stud* p)
{
    if (p == NULL) 
    {
        printf("\nList is empty.\n");
        return;
    }

    printf("\n-------Students Deatails------------\n");
	do{
		printf("\nName:%s, RollNo: %d , Standard:%d , Division:%c",p->name, p->rno ,  p->std , p->div);
		p = p->next;
		
	}while(p!=NULL);
}

void freeList(stud* head) {
	
	stud* nw ;
	while(head != NULL) {
		nw = head->next;
		free(head);
		head == NULL;
		head = nw;
	}
}

