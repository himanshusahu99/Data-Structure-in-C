#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void push(int * , int );
void pop(int * );
void traverse(int * );

int TOP = -1;

int main()
{
    int choice,item;
    int stack[MAX] ;



    while(1)
    {
        printf("\nMenu");
        printf("\n1. Push\n2.Pop\n3.Traverse\n4.exit\n");

        printf("\n Enter your Choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("\n enter Item\n");
            scanf("%d",&item);
            push(stack, item);
            break;

        case 2:
         pop( stack);
         break;

        case 3:
           traverse(stack);
           break;

        case 4:
            exit(0);


        }

    }
}

void push(int stack[], int item)
{
    if(TOP == MAX)
    {
        printf("Stack is Full\n");
        return ;
    }

    TOP++ ;
    stack[TOP] = item;
}



void pop(int stack[])
{
    int item;
     if (TOP  == -1 )
     {
         printf("stack is empty\n");
         return;

     }

     item = stack[TOP];
         TOP--;

         printf("deleted Item = %d\n", item);


}

void traverse(int stack[])
{
     int i;
    if(TOP == -1)
    {
        printf("stack is empty\n");
        return ;
    }

  i = TOP;

  while (i>=0)
  {
      printf("%d\t", stack[i]);
      i--;
  }
}
