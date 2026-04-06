/* Create a structure "Item" which includes below member variables:
   - itemName, quantity, price, amount.
   calculate the amount by accessing the member variable with the help of structure pointer.

*/

#include <stdio.h>
#include <stdlib.h>

//Structure definition
struct Item 
{
   char itemName[50];
   int quantity;
   int price;
   int amount;
};

//function declaration
struct Item* createStructure();
int  calculateAmount(struct Item* item);

int main(void)
{
   //function calling and returning
   struct Item* item = createStructure();

   //calculate amount of item
   int amount = calculateAmount(item);

   printf("\n********Item Details***********");
   printf("\nName    : %s", item->itemName);
   printf("\nQuantity: %d", item->quantity);
   printf("\nPrice   : %d", item->price);
   printf("\nAmount  : %d", item->amount);

   free(item);
   
   return 0;
}

struct Item* createStructure()
{
   struct Item* item = (struct Item*)malloc(sizeof(struct Item));
   if(item == NULL)
   {
      puts("Out of memory");
      exit (EXIT_FAILURE);
   }

   printf("\nEnter Item name: ");
   scanf("%s", item->itemName);

   printf("\nEnter Item quantity: ");
   scanf("%d", &item->quantity);

   printf("\nEnter Item price: ");
   scanf("%d", &item->price);

   return item;

}

int calculateAmount(struct Item* item)
{
   item->amount = item->price * item->quantity;

   return item->amount;
}