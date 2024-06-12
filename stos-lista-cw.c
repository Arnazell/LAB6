#include <stdio.h>
#include<stdlib.h>


typedef struct node
 { 
   int item; 
   struct node *next;
}NODE;
NODE *head=NULL;

void push(int x)
{
   // zaalokowanie pamieci
   NODE *p;
   p=(NODE*)malloc(sizeof(NODE));

   // dodanie do stosu
   p->item=x;
   p->next=head;
   head=p;
}

int pop()
{
   if(head==NULL)
   {
      printf("stos pusty\n");
      return 0;
   }
   else
   {
      int x;
      NODE *p;
      x=head->item;
      p=head;
      head=head->next;
      free(p);
      return x;
   }
}

int empty()
{
   if(head==NULL)
      return 1;
   else
      return 0;
}

int main()
{
   int i, x, head1;
   for(i=0;i<10;i++)
   {
      scanf ("%d", &x);
      push(x);
   }
   printf("czy pusty=%d\n",empty());
   for(;!empty();)
   printf("+++ze stosu: %d\n", pop());
}
