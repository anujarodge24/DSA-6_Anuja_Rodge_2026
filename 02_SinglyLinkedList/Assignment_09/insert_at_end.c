//Insert node at end

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//define Symbolic constants
#define SUCCESS 1

//define structure
struct node
{
    int data;
    struct node* next;
};

//Function declaration
struct node* create_node();
int create_list(struct node* p_list);
int insert_end(struct node* p_list, int new_data);
int destroy_list(struct node* p_list);
void show_list(struct node* p_list);

int main(void)
{
    struct node* start = NULL;
    int status;
    int end_data;

    start = create_node();
    
    //==========List creation===========
    status = create_list(start);
    assert(status == SUCCESS);
    printf("\nLinked List created successfully\n");

    printf("\n************* Before End Node Insertion **************\n");
    show_list(start);

    printf("\n\n*************After End Node Insertion ****************\n");
    printf("Enter end data: ");
    scanf("%d" , &end_data);
    status = insert_end(start, end_data);
    assert(status == SUCCESS);
    printf("\nHead node inserted successfully\n");


    show_list(start);

    //=========destroy list===========
    status = destroy_list(start);
    assert(status == SUCCESS);
    printf("\nLinked List destroyed successfully\n");


    return 0;


}

struct node* create_node(void)
{
    struct node* head_node = NULL;
    head_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == head_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }
    
    head_node->data = 0;
    head_node->next = NULL;

    return head_node;
}

int create_list(struct node* head)
{
    struct node* new_node = NULL , *prev_node = NULL;
    int choice = 0;

    do
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
        {
            puts("Out of memory");
            exit(EXIT_FAILURE);
        }
        printf("\nEnter data: ");
        scanf("%d", &new_node->data);
        new_node->next = NULL;

        //if first node is empty
        if(head->next == NULL)
        {
            head->next = prev_node =  new_node;

        }
        
        else
        {
            prev_node->next = new_node;
        }
        
        prev_node = new_node;
        
        printf("Do you want to enter the node(1/0): ");
        scanf("%d", &choice);
    } while (choice == 1);

    return (SUCCESS);
    
}


int insert_end(struct node* p_list, int new_data)
{
    struct node* run = NULL , *new_node = NULL;
   
    
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        exit (EXIT_FAILURE);
    }

    if(new_node == NULL)
    {
        puts("Out of memory");
        exit (SUCCESS);
    }

    new_node->data = new_data;
    new_node->next = NULL;

    
    run = p_list->next;
    while(run->next != NULL || run != NULL)
    {
        run = run->next;
    }

    run->next = new_node;

    return (SUCCESS);

}

void show_list(struct node* p_list)
{
    struct node* run = NULL;

    printf("[START]->");
    run = p_list->next;
    while(run != NULL)
    {
        printf("[%d]->", run->data);
        run = run->next;
    }
    printf("[END]");
}


int destroy_list(struct node* p_list)
{
    struct node* run = NULL;
    struct node* run_next = NULL;

    run = p_list;
    while(run != NULL){
        run_next = run->next;
        free(run);

        run = run_next;

    }

    return (SUCCESS);
}



