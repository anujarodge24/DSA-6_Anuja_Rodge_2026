/* 
write a c program to Create a Singly Linked list and  Display the addition of two consecutive nodes to the next node 
          
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 

O/P ---->    |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_AABB_|_700_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_800_| --> |_7_|_CCDD_|_NULL_|

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	int no;
	char name[20];
	struct student* next;
}slist;

slist* creation(slist*);
void display(slist*);
void add_nodes(slist*);
void freeList(slist*);

int main()
{
	slist* start = NULL;
	
    start = creation(start);
	if(start == NULL)
    {
        printf("List is Empty");
        return 0;
    }

    printf("\n****** Original List ********\n");
    display(start);


    //=======Add two consecutive nodes =======
    printf("\n\n ***** After Addition of consecutive node *******\n");
    add_nodes(start);
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
            printf("\nMemory allocation failed!");
            return NULL;
        }

		printf("Enter no and name:");
		scanf("%d %s",&nw->no, &nw->name);
		nw->next = NULL;
		
		if(head == NULL) {
			head = nw;
		}else{
			lst->next = nw;
		}
		
		lst = nw;
		printf("Do you want to enter new record? (1/0): ");
        scanf("%d", &ans);
    } while(ans == 1);

    return head;
}


void add_nodes(slist* p)
{
	slist* q, *nw;
	while(p !=NULL && p->next !=NULL)
	{
		q = p->next;
		nw = (slist*)malloc(sizeof(slist));
        if(nw == NULL)
        {
            printf("\nMemory allocation failed!");
            return;
        }
		
		nw ->no = p->no + q->no;
		snprintf(nw->name , sizeof(nw->name), "%s%s",p->name, q->name);
		
		nw->next = q->next;
		q->next = nw;

		p = nw->next;
	}
}
		
void display(slist* head)
{
    printf("[START]->");
	do{
		printf("|_%d_|_%s_|--> ",head->no ,  head->name );
		head = head->next;
		
	}while(head!=NULL);
    printf("[END]");

}

void freeList(slist* head) {
	
	slist* nw ;
	while(head != NULL) {
		nw = head->next;
		free(head);
		head == NULL;
		head = nw;
	}
}


	