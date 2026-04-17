/*
 write a c program to Create a singly linked list and search a particular node. 
          
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_500_| --> |_6_|_FF_|_NULL_|  
Enter : Key = 5

O/P ---->  
 |_5_|_EE_|_500_|
 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct SinglyLL
{
	int no;
	char name[20];
	struct SinglyLL* next;
}SL;
	

SL* creation(SL*);
void search(SL*, int);
void freeList(SL*);

int main(void)
{
	SL* start = NULL;        
	start = creation(start);
	
	int key;
	printf("\nEnter key for serch in linked list:");
	scanf("%d", &key);
	
    
	search(start, key);
	
	freeList(start);
	
	return 0;
}

SL* creation(SL* head)
{
	SL* nw, *lst;
	int ans;
	
	do{
		nw = (SL*)malloc(sizeof(SL));
		if (nw == NULL) 
        {
            printf("\nMemory allocation failed!");
            exit(EXIT_FAILURE);
        }
		
		printf("Enter no and name:");
		scanf("%d %s",&nw->no, &nw->name);
		nw->next = NULL;
		
		if (head == NULL) {
            head = nw;
        } else {
            lst->next = nw;
        }
        lst = nw;

        printf("Do you want to enter new record? (1/0): ");
        scanf("%d", &ans);
    } while(ans == 1);

    return head;
}

void search(SL* p, int key)
{
	
	while(p != NULL)
    {
		if(key == p->no) {
		    printf("\n|_%d_|_%s_|", p->no, p->name);
			return;
		}
		p = p->next;
		
	}
		
    printf("\nKey %d not found", key);
	
}

void freeList(SL* head) {
	
	SL* nw ;
	while(head != NULL) 
    {
        nw = head;
        head = head->next;
        free(nw);
		
	}
}



	
	