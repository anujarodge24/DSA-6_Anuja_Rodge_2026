/*
write a c program to Create a Singly linked list and Display the alternate nodes 

I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_NULL_|. 

O/P  ---->  |_1_|_AA_|_100_| --> |_3_|_CC_|_300_| --> |_5_|_EE_|_NULL_|

*/

//include header files
#include<stdio.h>
#include<stdlib.h>

//define structure
typedef struct singlyLinkedlist
{
	int no;
	char name[20];
	struct singlyLinkedlist* next;
}slist;

slist* create(slist*);
void alternate_display(slist*);
void freeList(slist*);

int main(void)
{
	slist* start = NULL;
	
    start = create(start);
	
    printf("\n --------Alternate nodes----------\n");
    alternate_display(start);

	freeList(start);
	return 0;
}

slist* create(slist* head)
{
	slist* nw , *lst = NULL;
	int ans;
	
	do{
		nw = (slist*)malloc(sizeof(slist));
        if(nw == NULL)
        {
            puts("out of memory");
            exit (EXIT_FAILURE);
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
		
        printf("\nDo you want to enter new record? (1/0): ");
        scanf("%d", &ans);

    } while(ans == 1);

    return head;
}

void alternate_display(slist* p)
{
	if(p == NULL)
		return;
	
    printf("[START]-->");
	do{
		printf("|_%d_|_%s_|-->", p->no, p->name);
		
		if(p->next == NULL)
			break;
		p = p->next->next;
		
	}while(p!=NULL);

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
