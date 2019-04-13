
// original linked list: 6->5->8->2->NULL

// when running:
// gcc delNodeFromLinkedList.c
// ./a.out

 
/* outcome:
[beliu: ~/Desktop/data-structure]$./a.out
6->5->8->2->NULL
deleting 6
5->8->2->NULL
deleting 8
5->2->NULL
deleting 2
5->NULL
deleting 5
NULL
NULL
*/


#include <stdio.h>
#include <stdlib.h>

struct node
{
   int value;
   struct node* next;
};


void printing(struct node* head)
{
   struct node *cur = head;

   while(cur != NULL)
   {
      printf("%d->",cur->value);
      cur = cur->next;
   }
   printf("NULL\n");
}

struct node* myLinkDel(struct node* head, int val)
{
   struct node *cur = head;
   if(head == NULL) return NULL;
   
   // we can chose either of the following two ways:
   // 1. introduce dummy head 
   // 2. wirte corner case:head->val==val
   if(head->value == val)  
   {                        
      struct node *next = head->next;
      printf("deleting %d\n", head->value);
      free(head);
      return next;
   }

   
   while (cur->next!= NULL) 
   {
      if (val == cur->next->value)
      {
         struct node *tmp = cur->next;
         printf("deleting %d\n", cur->next->value);
         cur->next = cur->next->next;
         
         free(tmp);
         break;
      }
      cur = cur->next;
   }
   return head;
}


void cleanUp(struct node *head)
{
   struct node *cleanPtr = head;
   while(cleanPtr != NULL)
   {
      struct node *temp = cleanPtr;
      cleanPtr = cleanPtr->next;
      free(temp);
   }
}


int main()
{
   struct node *test1 = malloc(sizeof(struct node));
   test1->value = 6;

   struct node *testPtr = test1;
   testPtr->next = malloc(sizeof(struct node));
   testPtr->next->value = 5;
   testPtr = testPtr->next;

   
   testPtr->next = malloc(sizeof(struct node));
   testPtr->next->value = 8;
   testPtr = testPtr->next;

   
   testPtr->next = malloc(sizeof(struct node));
   testPtr->next->value = 2;
   testPtr = testPtr->next;

   testPtr->next = NULL;

   printing(test1);
   test1 = myLinkDel(test1,6); //del head
   printing(test1);

   test1 = myLinkDel(test1,8); //del middle one
   printing(test1);

   test1 = myLinkDel(test1,2);  // del last one
   printing(test1);

   test1 = myLinkDel(test1,5); // del only one 
   printing(test1);
   
   test1 = myLinkDel(test1,9);  // del NULL
   printing(test1);

   cleanUp(test1);
 


}