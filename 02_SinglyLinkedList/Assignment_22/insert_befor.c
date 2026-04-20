/*

create a linnked list and insert a node before key node (given by user)
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
                 key: 3
                 data: 100, ZZ
O/P ---->  |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_100_|_ZZ_|_NULL_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_|

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
struct node* insert_before(struct node* head_node, int key);
void show_list(struct node* head_node);
void destroy_list(struct node* head_node);

int main(void)
{
    struct node* start = NULL;

    //List creation
    start = create(start);

    printf("\n******* Linked List *******\n");
    show_list(start);

    printf("\n***** Linked List after insert node *****\n");
    int key = 0;
    printf("Enter key:");
    scanf("%d", &key);

    start = insert_before(start, key);
    show_list(start);
    

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

struct node* insert_before(struct node* head_node, int key)
{
    if(head_node == NULL)
    {
        printf("\nList Empty");
        return NULL;
    }

    struct node* run = head_node;
    struct node* prev_node = NULL;


    while(run != NULL)
    {
        if(run->data == key)
            break;
        prev_node = run;
        run = run->next;
    }

    if(run == NULL )
    {
        printf("List data not found");
        return head_node;
    }
    

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }
    printf("Enter data and string:");
    scanf("%d %s", &new_node->data, new_node->str);
    
    if(run == head_node)
    {      
        new_node->next = head_node;
        head_node = new_node;
    }
    else{

        new_node->next = run;
        prev_node->next = new_node;
        
    }
    
    return head_node;
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


