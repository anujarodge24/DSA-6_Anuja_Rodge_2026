/*
Append list: create two linnked lists and append the list2 in list1.

I/P:
list_1  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
list_2  ---->   |_10_|_AAAA_|_10000_| --> |_20_|_BBBB_|_20000_|

O/P: 
list_1  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| --> |_10_|_AAAA_|_10000_| --> |_20_|_BBBB_|_20000_|
list_2  ---->   |_10_|_AAAA_|_10000_| --> |_20_|_BBBB_|_20000_|
*/

#include <stdio.h>
#include <stdlib.h>

//structure define
struct node 
{
    int data;
    char str[5];
    struct node* next;
};

//function declarations
struct node* create(struct node* head_node);
struct node* append(struct node* list1, struct node* list2);
void show_list(struct node* head_node);
void destroy_list(struct node* head_node);

int main(void)
{
    struct node* head_list1 = NULL;
    struct node* head_list2 = NULL;

    //List creations
    printf("\n******* first list creation ********\n");
    head_list1 = create(head_list1);

    printf("\n*******Second list creation *********\n");
    head_list2 = create(head_list2);
    
    printf("\nLinked List 1: \n");
    show_list(head_list1);

    printf("\nLinked List 2: \n");
    show_list(head_list2);

    //concatenete list
    struct node* head_list3 = append(head_list1, head_list2);
    printf("\nAfter list2 append in list1 List:\n");
    show_list(head_list3);

    //destroy list
    destroy_list(head_list1);
    head_list1 = NULL;
    
    destroy_list(head_list2);
    head_list2 = NULL;

    destroy_list(head_list3);
    head_list3 = NULL;
   
    return 0;
}


struct node* create(struct node* head_node)
{
    struct node* new_node = NULL, *last_node = NULL;
    int choice = 0;

    do{
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
        {
            printf("\nMemory allocation failed!");
            return NULL;
        }
        printf("\nEnter data and String: ");
        scanf("%d %s", &new_node->data, new_node->str);
        new_node->next = NULL;

        if(head_node == NULL)
        {
            head_node = last_node = new_node;
        }
        else{
            last_node->next = new_node;
        }

        last_node = new_node;

        printf("Do you want to enter another node(1/0):");
        scanf("%d", &choice);

    }while(choice == 1);

    return head_node;

}

struct node* append(struct node* list1 , struct node* list2)
{
    if(list1 == NULL && list2 == NULL)
    {
        return NULL;
    }

    if(list1 == NULL && list2 != NULL)
    {
        return list2;
    }

    if(list1 != NULL && list2 == NULL)
    {
        return list1;
    }

    struct node* temp = list1;

    while(temp->next != NULL)
    {
        temp = temp->next;

    }

    temp->next = list2;
    return list1;

}

void show_list(struct node* head_node)
{
    if(head_node == NULL)
    {
        printf("\nList is Empty!");
        return;
    }

    printf("[START]-->");
    struct node* p = head_node;
    for(  ; p != NULL; p = p->next)
    {
        printf("|_%d_|_%s_|-->", p->data, p->str);
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


