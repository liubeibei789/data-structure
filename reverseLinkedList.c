#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int value;
	struct node *next;
} Node;

int reverseLinkedList(Node** head)
{
   Node *dummy = calloc(1, sizeof(int));
   dummy->value = -1;
   dummy->next = *head;
   Node *cur = *head;
   Node *pre = dummy;

	while(cur->next != NULL)
	{
      Node *holder = cur->next;
      //printf("pre=%d,cur=%d,holder=%d\n",pre->value,cur->value,holder->value);
      cur->next = pre;

      // move pointers
      pre = cur;
      cur = holder;  
	}
   cur->next = pre;
	free(dummy);
   (*head)->next = NULL;
	*head = cur;
	return 0;
}

void printing(Node* head)
{
	while(head != NULL)
	{
		printf("%d->", head->value);
		head = head->next;
	}
	printf("NULL\n");
}


int main()
{
   Node *head = calloc(1, sizeof(int));
   head->value = 7;
   Node *ptr = head;

   ptr->next = calloc(1, sizeof(int));
   ptr->next->value = 4;
   ptr = ptr->next;

   ptr->next = calloc(1, sizeof(int));
   ptr->next->value = 3;
   ptr = ptr->next;

   ptr->next = calloc(1, sizeof(int));
   ptr->next->value = 8;
   ptr = ptr->next;

   ptr->next = NULL;


   printing(head);
   reverseLinkedList(&head);
   printing(head);
	return 0;
}