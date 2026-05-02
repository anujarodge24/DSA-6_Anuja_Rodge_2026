/* write a c program to Create a doubly linked list and Delete a node at Head. */

#include <stdio.h>
#include <stdlib.h>

struct node 
{ 
    int data;
    struct node* next;
    struct node* prev; 
};

// Function Declarations
struct node* create_node(); 
void create_list(struct node* p_list);
void delete_head(struct node* p_list);
void show_list(struct node* p_list);
void free_list(struct node* p_list);

int main(void) 
{

    struct node* start = create_node();
    
    //list creation
    create_list(start);
    printf("\n**** Doubly Linked List before head node deletion ****\n");
    show_list(start);
    
    
    printf("\n***** Head node deletion *******\n");
    delete_head(start);
    show_list(start);
    
    free_list(start);
    
    return 0;
}


struct node* create_node()
{
    struct node* dummy = (struct node*)malloc(sizeof(struct node));
    if (dummy == NULL) 
    {
        puts("Memory allocation failed!");
        exit (EXIT_FAILURE);

    }
    dummy->next = NULL;
    dummy->prev = NULL;


    return dummy;
}

void create_list(struct node* p_list) 
{
    if(p_list == NULL)
    {
        printf("\nDummmy node not created");
        return;
    }

    struct node* lst = NULL, *new_node = NULL;
    int choice = 0;

    do
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
        {
            puts("Memory allocation failed!");
            return;
        }
        printf("\nEnter data: ");
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        new_node->prev = NULL;

        if(p_list->next == NULL)
        {
            p_list->next = new_node;
            new_node->prev = p_list;
        }
        else{
            lst->next = new_node;
            new_node->prev = lst;
        }
        lst = new_node;

        printf("\nDo you want to enter another node(1/0): ");
        scanf("%d", &choice);

    } while (choice == 1);

    
    
}

void delete_head(struct node* p_list) 
{
    if(p_list == NULL)
    {
        printf("Dummy node not created");
        return;
    }

    if(p_list->next == NULL)
    {
        printf("\nList not created");
        return;
    }

    struct node* temp = p_list->next; 
    
    if(temp->next != NULL)
    {
       struct node* temp_next = temp->next;
       p_list->next = temp_next;
       temp_next->prev = p_list;
       free(temp);
       return;
    }

    p_list->next = temp->next;
    free(temp);
}

void show_list(struct node* p_list) 
{   
    if(p_list == NULL)
    {
        printf("Dummy node not created");
        return;
    }

    if(p_list->next == NULL)
    {
        printf("\nList not created");
        return;
    }

    struct node* run = p_list->next;
    

    printf("\n[START]<->");
    while (run != NULL) 
    {
        printf("[%d]<->", run->data);
        run = run->next;
    }
    printf("[END]\n");
}

void free_list(struct node* p_list) 
{
    struct node* temp;
    while (p_list != NULL) 
    {
        temp = p_list;
        p_list = p_list->next;
        free(temp);
    }

    printf("List memory cleared.\n");
}