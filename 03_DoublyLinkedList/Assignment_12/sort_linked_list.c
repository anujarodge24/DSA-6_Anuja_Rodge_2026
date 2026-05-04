/* write a c program to sort the doubly linked list. */


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
void sort(struct node* p_list);
void show_list(struct node* p_list);
void free_list(struct node* p_list);

int main(void) 
{

    struct node* start = create_node();
    
    //list creation
    create_list(start);
    printf("\n**** Doubly Linked List ****\n");
    show_list(start);
    

    printf("\n**********************************\n");
    printf("\nSorted Doubly Linked List:\n");
    sort(start);
    show_list(start);
    printf("\n**********************************\n");

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

void sort(struct node* p_list) 
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

    struct node *i, *j;
    int temp;


    for (i = p_list->next; i->next != NULL; i = i->next) 
    {
        
        for (j = i->next; j != NULL; j = j->next) 
        {
            if (j->data < i->data) 
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }

    }
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