//Insert node at end

#include <stdio.h>
#include <stdlib.h>

//define symbolic constants
#define SUCCESS    1
#define LIST_EMPTY 0

//define structure
struct node
{
    int data;
    struct node* next;
};

//function declarations
struct node* create_node();
int create_list(struct node* p_list);
int insert_end(struct node* p_list, int end_data);
void show_list(struct node* p_list);
int destroy_list(struct node* p_list);

int main(void)
{
    struct node* start = create_node();

    int status , end_data;

    //========== create linked list ===========
    status = create_list(start);

    printf("\n************ Before End node Insertion **************\n");
    show_list(start);

    printf("\n\n*********** After End node Insertion *****************\n");
    printf("Enter data: ");
    scanf("%d", &end_data);
    status = insert_end(start,end_data);
    show_list(start);

    // ========== destroy list ==============
    status = destroy_list(start);

    return 0;
}

struct node* create_node()
{
    struct node* head_node = (struct node*)malloc(sizeof(struct node));
    if(head_node == NULL)
    {
        puts("out of memory");
        exit (EXIT_FAILURE);
    }

    head_node->data = 0;
    head_node->next = NULL;

    return (head_node);
}

int create_list(struct node* p_list)
{
    struct node* new_node = NULL, *prev_node = NULL;
    int choice = 0;

    do {
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
        {
            puts("out of memory");
            exit(EXIT_FAILURE);
        }
        printf("\nEnter data: ");
        scanf("%d", &new_node->data);

        if(p_list->next == NULL)
        {
            p_list->next = prev_node = new_node;
        }
        else{
            prev_node->next = new_node;
        }
        prev_node = new_node;

        printf("Do you want to enter another node(1/0): ");
        scanf("%d" , &choice);

    }while(choice == 1);

    return (SUCCESS);
}

int  insert_end(struct node* p_list, int end_data)
{
    struct node* new_node = NULL;
    struct node* run = NULL;

    if(p_list->next == NULL)
    {
        return (LIST_EMPTY);
    }

    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }
    new_node->data = end_data;
    new_node->next = NULL;

    run = p_list->next;

    while(run->next != NULL)
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

    while(run != NULL)
    {
        run_next = run->next;
        free(run);

        run = run_next;
    }

    return (SUCCESS);
}
