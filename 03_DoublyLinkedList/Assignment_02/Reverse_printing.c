/* write a c program to Create Doubly linked list and display it in reverse order. */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

//Function declaration
struct node* create_list(struct node* p_list);
void show_list(struct node* p_list);
void reverse_printing(struct node* p_list);
void destroy_list(struct node* p_list);


int main(void)
{
    struct node* start = NULL;

    //List creation
    start = create_list(start);

    //List display
    printf("\n*** Doubly Linked List***\n");
    show_list(start);

    printf("\n*** Reverse Order Printing ***\n");
    reverse_printing(start);

    //destroy List
    destroy_list(start);

    printf("\nMemory free successfully!");

    return 0;
}

struct node* create_list(struct node* p_list)
{
    struct node* lst = NULL, *new_node = NULL;
    int choice = 0;

    do
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
        {
            puts("Memory allocation failed!");
            return NULL;
        }
        printf("\nEnter data: ");
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        new_node->prev = NULL;

        if(p_list == NULL)
        {
            p_list = new_node;
        }
        else{
            lst->next = new_node;
            new_node->prev = lst;
        }
        lst = new_node;

        printf("Do you want to enter another node(1/0): ");
        scanf("%d", &choice);

    } while (choice == 1);

    return p_list;
    
}

void reverse_printing(struct node* p_list)
{
    if(p_list == NULL)
    {
        printf("List is Empty!");
        return;
    }
    
    struct node* run = p_list;
    while(run->next != NULL)
    {
        run = run->next;
    }

    printf("[START]->");
    while(run != NULL)
    {
        printf("[%d]<->", run->data);
        run = run->prev;
    }
    printf("[END]");


}

void show_list(struct node* p_list)
{
    if(p_list == NULL)
    {
        printf("List is Empty!");
        return;
    }

    struct node* run = p_list;

    printf("[START]->");
    while(run != NULL)
    {
        printf("[%d]<->", run->data);
        run = run->next;

    }
    printf("[END]");
}

void destroy_list(struct node* p_list)
{
    if(p_list == NULL)
    {
        printf("List is Empty!");
        return;
    }

    struct node* temp = NULL;
    while(p_list != NULL)
    {
        temp = p_list;
        p_list = p_list->next;
        free(temp);
       

    }

}



