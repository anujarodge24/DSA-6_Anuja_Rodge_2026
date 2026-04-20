/* write a c program to Create Linked List using Recursion. */

#include <stdio.h>
#include <stdlib.h>

//structure defination
struct node
{
    int data;
    struct node* next;
};


//function declarations
struct node* creation();
void show_list(struct node* head_node);
void destroy_list(struct node* head_node);

int main()
{
    struct node* start = NULL;

    //List creation
    start = creation();

    printf("\n******* Linked List *******\n");
    show_list(start);

    destroy_list(start);

    return 0;
    
}

struct node* creation()
{
    int data = 0 , choice = 0;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;

    printf("\nDo you want to Enter another node(1/0):");
    scanf("%d", &choice);

    if(choice == 1)
    {
        new_node->next = creation();
    }

    return new_node;

}

void show_list(struct node* head_node)
{
    if(head_node == NULL)
    {
        printf("\nList Empty");
        return;
    }
    
    printf("[START]-->");
    struct node* temp = head_node;
    for(  ; temp != NULL; temp = temp->next)
    {
        printf("[%d]-->", temp->data);
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