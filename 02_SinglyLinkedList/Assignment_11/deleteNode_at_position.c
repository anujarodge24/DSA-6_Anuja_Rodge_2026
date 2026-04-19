/* write a c program to Create a Singly linked list and Delete the node in the given position */

#include <stdio.h>
#include <stdlib.h>


#define SUCCESS      1
#define EMPTY_LIST   2
#define FAILURE      0


//structure declarations
struct node
{
    int data;
    struct node* next;
};

//function declarations
struct node* create_node();
int create_list(struct node* p_list);
int delete_at_position(struct node* p_list, int position);
void show_list(struct node* p_list, const char* msg);
int destroy_list(struct node* p_list);

int main(void)
{
    struct node* start = NULL;
    int status = 0;

    start = create_node();

    status = create_list(start);
    show_list(start, "Original list : ");

    printf("\n*********************************************************\n");
    int position = 0;
    printf("\nEnter Position: ");
    scanf("%d", &position);

    status = delete_at_position(start, position);
    if(status == SUCCESS)
        show_list(start, "Showing list after deletion of node at given position:\n");
    else if(status == FAILURE)
        printf("Position is not correct");
    else 
        printf("List is Empty");  
         
    
    printf("\n********************************************************\n");
    status = destroy_list(start);
    if(status == SUCCESS)
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


int delete_at_position(struct node* p_list, int pos) 
{
    if(p_list == NULL)
    {
        printf("\nList not created!");
        exit (EMPTY_LIST);
    }

    if (pos < 1) {
        printf("Invalid position!\n");
        return (EXIT_FAILURE);
    }
    
    struct node* delete_node = NULL;
    if (pos == 1) 
    {
        delete_node = p_list->next;
        p_list->next = delete_node->next;
        free(delete_node);
        return (SUCCESS);
    }

    struct node* run = p_list->next;
    for (int i = 1; i < pos - 1 && run != NULL; i++) {
        run = run->next;
    }

    if (run == NULL) 
    {
        printf("Position out of range!\n");
        return (FAILURE);
    }
    
    delete_node = run->next;
    run->next = delete_node->next;

    free(delete_node);
    delete_node = NULL;

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
        printf("\nList not created!");
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






	