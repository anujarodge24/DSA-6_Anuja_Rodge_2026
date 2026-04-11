/*
write a c program to Create a Singly linked list and swap the two consecutive nodes.

I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_500_| --> |_6_|_FF_|_NULL_|  

O/P  ---->   |_2_|_BB_|_100_| --> |_1_|_AA_|_200_| --> |_4_|_DD_|_300_| --> |_3_|_CC_|_400_| --> |_6_|_FF_|_500_| --> |_5_|_EE_|_NULL_|

*/

//include headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure definition
typedef struct singlyLL
{
    int data;
    char ch[5];
    struct singlyLL* next;

}SL;

//Function declarations
SL* create(SL*);
SL* swap(SL*);
void display(SL*);
void freeList(SL*);

int main(void)
{
	SL* start = NULL;
	
    start = create(start);

    printf("\n---------- Original List --------\n");
    display(start);
	
    printf("\n -------- Swapping of consecutive nodes ----------\n");
    start = swap(start);
    display(start);

	freeList(start);

	return 0;
}

SL* create(SL* head)
{
	SL* nw , *lst = NULL;
	int ans;
	
	do{
		nw = (SL*)malloc(sizeof(SL));
        if(nw == NULL)
        {
            puts("out of memory");
            exit (EXIT_FAILURE);
        }
		
        printf("Enter no and name:");
		scanf("%d %s",&nw->data, &nw->ch);
		
        nw->next = NULL;
		
		if(head == NULL) {
			head = nw;
		}else{
			lst->next = nw;
		}
		
		lst = nw;
		
        printf("\nDo you want to enter new record? (1/0): ");
        scanf("%d", &ans);

    } while(ans == 1);

    return head;
}

SL* swap(SL* head)
{
	if(head == NULL || head->next == NULL)
		return head;

    SL* p = head;

    while(p != NULL && p->next != NULL)
    {
        SL* q = p->next;

        int val = p->data;
        p->data = q->data;
        q->data = val;

        char temp[5];
        strcpy(temp , p->ch);
        strcpy(p->ch, q->ch);
        strcpy(q->ch , temp);

        p = q->next;

    }

    return head;
}

void display(SL* p)
{
    if(p == NULL)
    {
        printf("\nList is Empty.");
        return;

    }
		
	
    printf("[START]-->");
	
    while(p !=NULL)
    {
		printf("|_%d_|_%s_|-->", p->data, p->ch);
		
		p = p->next;
		
	}

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
