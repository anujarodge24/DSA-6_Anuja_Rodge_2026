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
struct node* delete_before(struct node* head_node, int key);
void show_list(struct node* head_node);
void destroy_list(struct node* head_node);

int main(void)
{
    struct node* start = NULL;

    //List creation
    start = create(start);

    printf("\n******* Linked List *******\n");
    show_list(start);

    printf("\n***** Linked List after node deletion *****\n");
    int key = 0;
    printf("Enter key:");
    scanf("%d", &key);

    start = delete_before(start, key);
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

struct node* delete_before(struct node* head_node, int key)
{
    if(head_node == NULL)
    {
        printf("\nList Empty");
        return NULL;
    }

    struct node* run_next = head_node;
    struct node* run_prev = NULL;
    struct node* delete_node = NULL;


    while(run_next != NULL)
    {
        if(run_next->data == key)
            break;
        run_prev = delete_node;
        delete_node = run_next;
        run_next = run_next->next;
    }

    if(run_next == NULL )
    {
        printf("List data not found");
        return head_node;
    }
    
    //for first position
    if(run_next == head_node)
    {      
        printf("\nNo node present infront of head_node for deletion");
    }

    //for second position
    else if(run_prev == NULL)
    {
        head_node = run_next;
        free(delete_node);
    }
    
    else
    {
        run_prev->next = run_next;
        free(delete_node);
        delete_node = NULL;     
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


