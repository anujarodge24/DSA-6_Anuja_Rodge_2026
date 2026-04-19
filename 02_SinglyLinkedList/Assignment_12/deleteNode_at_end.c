/* write a c program to Create a Singly linked list and Delete the node at the last position. */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS      1
#define EMPTY_LIST   2


//structure declarations
struct node
{
    int data;
    struct node* next;
};

//function declarations
struct node* create_node();
int create_list(struct node* p_list);
int remove_end(struct node* p_list);
void show_list(struct node* p_list, const char* msg);
int destroy_list(struct node* p_list);

int main(void)
{
    struct node* start = NULL;
    int status = 0;

    //crete dummy node which points to linked list
    start = create_node();

    //to form linked list
    status = create_list(start);
    show_list(start, "Original list : ");

    printf("\n*********************************************************\n");
    status = remove_end(start);
    assert(status == SUCCESS);
    show_list(start, "Showing list after remove_end():\n");
    
    printf("\n********************************************************\n");
    status = destroy_list(start);
    assert(status == SUCCESS);
    start = NULL;
    printf("List is destroyed successfully\n");


    return 0;
}

struct node* create_node(void)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        exit (EXIT_FAILURE);
    }

    new_node->data = 0;
    new_node->next = NULL;

    return new_node;
}

int create_list(struct node* p_list)
{
    if(p_list == NULL)
    {
        printf("\nDummy node not created!");
        exit (EXIT_FAILURE);
    }

    struct node* new_node = NULL , *prev_node = NULL;
    int choice = 0;

    do {
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
        {
            printf("\nMemory allocation failed!");
            exit (EXIT_FAILURE);
        }

        printf("\nEnter data: ");
        scanf("%d" , &new_node->data);
        new_node->next = NULL;

        if(p_list->next == NULL)
        {
            p_list->next = prev_node = new_node;
        }

        else 
        {
            prev_node->next = new_node;

        }
        prev_node = new_node;

        printf("\nDo you want to enter another node: ");
        scanf("%d", &choice);

    }while(choice == 1);

    return (SUCCESS);
}

int remove_end(struct node* p_list)
{
    if(p_list == NULL)
    {
        printf("\nList not created!");
        exit (EMPTY_LIST);
    }

    if(p_list->next == NULL)
    {
        printf("\nList Empty");
        exit (EMPTY_LIST);
    }
    
    struct node* run = p_list->next;

    while(run->next->next != NULL)
    {
        run = run->next;
    }

    free(run->next);
    run->next = NULL;

    return (SUCCESS);
}

void show_list(struct node* p_list, const char* msg)
{
    if(p_list == NULL)
    {
        printf("\nList not created!");
        exit (EMPTY_LIST);
    }

    struct node* run = NULL;

    if(msg != NULL)
    {
        puts(msg);
    }

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
    if(p_list == NULL)
    {
        exit (EMPTY_LIST);
    }

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





















