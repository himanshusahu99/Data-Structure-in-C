#include<stdio.h>
#include<stdlib.h>


void push();
void pop( );
void traverse( );



struct node
{
    int info;
    struct node *link;
} *TOP = NULL;

int main()
{
    int choice,item;




    while(1)
    {
        printf("\nMenu");
        printf("\n1. Push\n2.Pop\n3.Traverse\n4.exit\n");

        printf("\n Enter your Choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop( );
            break;

        case 3:
            traverse();
            break;

        case 4:
            exit(0);


        }

    }
}

void push()
{
    struct node *NEW;
    int item;
    NEW = (struct node * ) malloc(sizeof(struct node));
          if (NEW == NULL)
    {
        printf("overflow \n");
        exit(0 );

    }

    printf("\n enter item value\n ");
    scanf("%d", &item);

    NEW -> info = item;
    NEW -> link = TOP;

    TOP = NEW;
}



void pop()
{
   int item;
   struct node *temp;

   if(TOP == NULL)
   {
       printf("Underflow \n");
       exit(0);
   }


   temp = TOP ;
   TOP = TOP->link;

    printf("deleted item is %d\n\n", temp->info) ;
    free(temp);

}

void traverse()
{
    struct node *ptr;
    ptr = TOP ;

      if(TOP == NULL)
   {
       printf("Stack is empty  \n");
       exit(0);
   }

    while(ptr != NULL)
    {
        printf("%d\t ", ptr->info);
        ptr = ptr->link;
    }



}
