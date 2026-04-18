/* write a c program to Create a Singly linked list and Find and print the middle element.  */

#include<stdio.h>
#include<stdlib.h>

typedef struct SinglyLL 
{
	int data;
	struct SinglyLL* next;
}SL;

SL* create(SL*);
void find_middle(SL*);
void show_list(SL*);
void freeList(SL*);

int main(void)
{
	SL* start = NULL;

    //====== List creation =========
	start = create(start);

    printf("\n ******** Original List ********\n");
    show_list(start);

    //====== Middle node ============
    printf("\n********* Middle node **********");
	find_middle(start);

	freeList(start);
	
	return 0;
}

SL* create(SL* head)
{
	SL* nw, *lst;
	int ans;
	
	do {
		nw = (SL*)malloc(sizeof(SL));
        if(nw == NULL)
        {
            printf("Memory allocation failed!");
            return NULL;
        }

		printf("\nEnter data:");
		scanf("%d", &nw->data);
		nw->next = NULL;
	    
		if(head == NULL) {
			head = nw;
		}
		else {
			lst->next = nw;
		}
		lst = nw;
		
		printf("\nDo you want to Enter new data?(1/0):");
		scanf("%d", &ans);

	}while(ans == 1);
	
	return head;
}

/*when we given even data then we have to print  before element then we have to give condion
while(fast!=NULL && fast->next->!=NULL)*/

void find_middle(SL* fast) 
{
    if(fast == NULL)
    {
        printf("\nEmpty list");
    }

	SL* slow = fast;
	
	while(fast!=NULL && fast->next!=NULL)   //this print middle and and data is in even then this print after element
	{
		slow = slow->next;
		fast = fast->next->next;
		
	}
	printf("\n\nmiddle data:[%d]", slow->data);
}

void show_list(SL* p_list)
{
    SL* run = NULL;
    
    printf("[START]->");
    run = p_list;

    while(run != NULL)
    {
        printf("[%d]->", run->data);
        run = run->next;
    }

    printf("[END]");
    
}

void freeList(SL* head)
{
	SL* temp;

	while(head != NULL) 
    {
		temp = head->next;
		free(head);
		head = temp;
	}

}

			
	
	
	
	