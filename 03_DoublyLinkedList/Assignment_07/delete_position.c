// Delete node at given position in Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// Function declarations
struct node* create_node();
void create_list(struct node *p_list);
void delete_at_position(struct node *p_list, int position);
void show_list(struct node *p_list);
void free_list(struct node *p_list);

int main()
{
    struct node *start = create_node();

    // Create list
    create_list(start);

    printf("\n**** Doubly Linked List before deletion ****\n");
    show_list(start);

    int position;

    printf("\nEnter position for deletion: ");
    scanf("%d", &position);

    delete_at_position(start, position);

    printf("\n**** Doubly Linked List after deletion ****\n");
    show_list(start);

    free_list(start);

    return 0;
}

// Create dummy node
struct node* create_node()
{
    struct node *dummy = (struct node*)malloc(sizeof(struct node));

    if(dummy == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    dummy->next = NULL;
    dummy->prev = NULL;

    return dummy;
}

// Create doubly linked list
void create_list(struct node *p_list)
{
    struct node *new_node, *last = NULL;
    int choice;

    do
    {
        new_node = (struct node*)malloc(sizeof(struct node));
         if(new_node == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &new_node->data);

        new_node->next = NULL;
        new_node->prev = NULL;

        
        if(p_list->next == NULL)
        {
            p_list->next = new_node;
            new_node->prev = p_list;
        }
        else
        {
            last->next = new_node;
            new_node->prev = last;
        }

        last = new_node;

        printf("Do you want to add another node (1/0): ");
        scanf("%d", &choice);

    } while(choice == 1);
}

void delete_at_position(struct node *p_list, int position)
{
    if(p_list == NULL)
    {
        printf("Dummy node not created!\n");
        return;
    }

    if(p_list->next == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if(position <= 0)
    {
        printf("Invalid position!\n");
        return;
    }

    struct node *p = p_list;

    for(int i = 1; i < position && p->next != NULL; i++)
    {
        p = p->next;
    }

    if(p->next == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    struct node *delete_node = p->next;

    p->next = p->next->next;

    if(delete_node->next != NULL)
    {
        delete_node->next->prev = p;
    }

    free(delete_node);

    printf("Node deleted successfully.\n");
}

// Display list
void show_list(struct node *p_list)
{
    struct node *run = p_list->next;

    if(run == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("\n[START] <-> ");

    while(run != NULL)
    {
        printf("[%d] <-> ", run->data);
        run = run->next;
    }

    printf("[END]\n");
}

// Free memory
void free_list(struct node *p_list)
{
    struct node *temp;

    while(p_list != NULL)
    {
        temp = p_list;
        p_list = p_list->next;
        free(temp);
    }

    printf("\nList memory cleared.\n");
}