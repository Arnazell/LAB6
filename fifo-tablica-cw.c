#include <stdio.h>
#define N 100
int fifo[N];
int head=0;
int tail=0;
int l=0;

void put(int x)
{
   // jesli jest miejsce
   if (l<N)
   {
      fifo[tail]=x;
      tail=(tail+1)%N;
      l++;
   }
   else
      printf("Kolejka pelna\n");
}

int get()
{
   // jesli kolejka nie jest pusta
   if (l>0)
   {
      int x=fifo[head];
      head=(head+1)%N;
      l--;
      return x;
   }
   else
      printf("Kolejka pusta\n");
      return -1;
}

// ok
int full ()
 {
   return l >= N;
 }
 // ok
int empty()
 {
   return l<=0;
 }

int main()
{
   int i, x;
   for(i=0;i<10;i++)
   {
      scanf ("%d", &x);
      put(x);
   }
   for (i=head; i<tail;i++)
   printf("-- %d\n",fifo[i]);
   printf("dlugosc kolejki=%d\n",l);
   printf ("--- head=%d\n--- tail=%d\n", head,tail);
   printf("czy pelny=%d\n",full());
   printf("czy pusty=%d\n",empty());
   for(i=0;i<5;i++)
      printf("+++z fifo: %d\n", get());
   printf("dlugosc kolejki=%d\n",l);
   printf ("--- head=%d\n--- tail=%d\n", head,tail);
}
