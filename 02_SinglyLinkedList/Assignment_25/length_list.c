/* 
create a linnked list and print the number of nodes the list have. (size of list)
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
O/P ---->  4
*/

#include <stdio.h>
#include <stdlib.h>

//structure define
struct node 
{
    int data;
    char str[5];
    struct node* next;
};

//function declarations
struct node* create(struct node* head_node);
int length(struct node* head_node);
void show_list(struct node* head_node);
void destroy_list(struct node* head_node);

int main(void)
{
    struct node* start = NULL;

    //List creation
    start = create(start);

    printf("\n******* Linked List *******\n");
    show_list(start);

    //Length display
    int len = length(start);
    printf("\nLength of Linked List:%d", len);

    //destroy list
    destroy_list(start);
    start = NULL;

    return 0;
}


struct node* create(struct node* head_node)
{
    struct node* new_node = NULL, *last_node = NULL;
    int choice = 0;

    do{
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
        {
            printf("\nMemory allocation failed!");
            return NULL;
        }
        printf("\nEnter data and String: ");
        scanf("%d %s", &new_node->data, new_node->str);
        new_node->next = NULL;

        if(head_node == NULL)
        {
            head_node = last_node = new_node;
        }
        else{
            last_node->next = new_node;
        }

        last_node = new_node;

        printf("\nDo you want to enter another node(1/0):");
        scanf("%d", &choice);

    }while(choice == 1);

    return head_node;

}

int length(struct node* head_node)
{
    if(head_node == NULL)
    {
        printf("\nList is Empty");
        return 0;;
    }

    int count = 0;
    struct node* run = head_node;

    while(run != NULL)
    {
        count ++;
        run = run->next;
    }

    return count;
}

void show_list(struct node* head_node)
{
    if(head_node == NULL)
    {
        printf("\nList is Empty!");
        return;
    }

    printf("[START]-->");
    struct node* p = head_node;
    for(  ; p != NULL; p = p->next)
    {
        printf("|_%d_|_%s_|-->", p->data, p->str);
    }
    printf("[END]");

}

void destroy_list(struct node* head_node)
{
    if(head_node == NULL)
    {
        return;
    }

    struct node* temp = NULL;

    while(head_node != NULL)
    {
        temp = head_node;
        head_node = head_node->next;
        free(temp);
        temp = NULL;    
    }
}


