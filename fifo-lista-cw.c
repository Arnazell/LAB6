#include <stdio.h>
#include<stdlib.h>

typedef struct node
 { 
   int item; 
   struct node *next;
}NODE;

NODE *head=NULL;
NODE *tail=NULL;

void put(int x)
{
   // zaalokowanie pamieci
   NODE *p=(NODE*)malloc(sizeof(NODE));
   p->item=x;
   p->next=NULL;
   // jesli lista jest pusta
   if (head==NULL)
      head=p;
   // jesli nie jest pusta
   else
      tail->next=p;
   tail=p;
}

int get()
{
   // jesli lista nie jest pusta
   if (head!=NULL)
   {
      int x=head->item;
      NODE *p=head;
      head=head->next;
      free(p);
      return x;
   }
   else
      printf("Kolejka pusta\n");
      return -1;
}

int empty()
{
   return head==NULL;
}

int main()
{
   int i, x;
   for(i=0;i<10;i++)
   {
      scanf ("%d", &x);
      put(x);
   }
   printf("czy pusty=%d\n",empty());
   for(;!empty();)
      printf("+++z FIFO: %d\n", get());
}
