/* 
write a c program to Re-Arrange doubly linked list in pair format.
input -> 6 <-> 1 <-> 9 <-> 4 <-> 3 <-> 8 <-> 2
output -> 1 <-> 6 <-> 4 <-> 9 <-> 3 <-> 8 <-> 2

If first value is greater than second then swap  , if 3rd value is less than 4th then swap same for remaining pair
*/

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
void pair_rearrange(struct node* p_list);
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
    printf("\nRarrange Consecutive nodes: \n");
    pair_rearrange(start);
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

void pair_rearrange(struct node* p_list) 
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


    struct node *run = p_list->next;
    struct node* run_next = NULL;


    while(run != NULL && run->next != NULL)
    {
        run_next = run->next;

        if(run->data > run_next->data)
        {
            int temp = run->data;
            run->data = run_next->data;
            run_next->data = temp;
        }

        run = run->next->next;
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