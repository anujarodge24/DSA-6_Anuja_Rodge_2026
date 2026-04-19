#include<stdio.h>
#include<stdlib.h>

typedef struct singlyLinkedList
{
	int no;
	struct singlyLinkedList* next;
}slist;

slist* creation(slist*);
void display(slist*);
slist* sortList(slist*);
void freeList(slist*);

int main(void)
{
	slist* start = NULL;
	
	start = creation(start);
    
    printf("\n**** Original Linked List *****\n");
    display(start);

	start = sortList(start);

	printf("\n****** Sorted Linked List ******\n ");
	display(start);

	freeList(start);
	
	return 0;
}

slist* creation(slist* head)
{
	slist* nw , *lst = NULL;
	int ans;
	
	do{
		nw = (slist*)malloc(sizeof(slist));
        if(nw == NULL)
        {
            printf("\nMemory not created!");
            return NULL;
        }

		printf("Enter no: ");
		scanf(" %d",&nw->no);
		nw->next = NULL;
		
		if(head == NULL) 
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


slist* sortList(slist* head)
{
    if(head == NULL)
    {
        printf("\nList is Empty!");
        return NULL;
    }

	slist* p , *q = NULL;
	int i_tmp;
	
	
	for(p = head; p->next != NULL; p = p->next) 
	{
		for(q = p->next; q!=NULL ; q = q->next)
		{
			if(p->no > q->no) 
            {
				
				i_tmp = p->no;
				p->no = q->no;
				q->no = i_tmp;
			}
		}
	
	}
	return head;
}


void display(slist* head)
{
    if(head == NULL)
    {
        printf("\nList is Empty");
        return;
    }

    printf("[START]-->");
    slist* temp = head;
	while(temp != NULL)
	{
		printf("[%d]-->", temp->no);
		temp = temp->next;
		
	}
    printf("[END]");
}
void freeList(slist* head) 
{
	slist* nw ;
	while(head != NULL) {
		nw = head->next;
		free(head);
		head == NULL;
		head = nw;
	}
}

