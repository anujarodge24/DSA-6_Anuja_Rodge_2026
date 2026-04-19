/*
write a c program to Create a Singly linked list and Display it in reverse order using recursive funciton.
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_|
O/P :
------  
4 DD
3 CC
2 BB
1 AA

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct SinglyLL {
    int data;
    char ch[5];
    struct SinglyLL* next;
}SL;

//Function declaration
SL* creation(SL*);
void ReverseDisplay(SL*);
void display(SL*);
void freeList(SL*);


int main(void)
{
    SL* start = NULL;
    start = creation(start);

    printf("\n***************** Original Linked List *********************\n");
    display(start);

    printf("\n\nDisplay Reverse Printing: ");
    ReverseDisplay(start);

    freeList(start);

    return 0;

}

SL* creation(SL* head)
{
	SL* nw, *lst;
	int ans;
	
	do{
		nw = (SL*)malloc(sizeof(SL));
        if(nw == NULL)
        {
            printf("\nMemory allocation failed!");
            exit (EXIT_FAILURE);
        }
		printf("Enter data and str:");
		scanf("%d %s",&nw->data, nw->ch);
		nw->next = NULL;
		
		if (head == NULL) 
		{
            head = nw;
        } 
		else 
		{
            lst->next = nw;
        }
        lst = nw;

        printf("Do you want to enter new record? (1/0): ");
        scanf("%d", &ans);

    } while(ans == 1);

    return head;
}

void ReverseDisplay(SL* head)
{
    if(head == NULL)
        return;
    

    ReverseDisplay(head->next); 
    printf("\n%d  %s", head->data, head->ch);

    
}

void display(SL* head_node)
{
    if (head_node == NULL) 
    {
        printf("\nList is empty.\n");
        return;
    }
    
    SL* p = head_node;

    printf("[START]-->");
	do{
		printf("|_%d_|_%s_|-->", p->data, p->ch);
		p = p->next;
		
	}while(p!=NULL);

    printf("[END]");
}


void freeList(SL* head) {
	
	SL* nw ;
	while(head != NULL) {
		nw = head->next;
		free(head);
		head == NULL;
		head = nw;
	}
}
