
#include<stdio.h>
#include<stdlib.h>
//function prototypes
void create();
void display();
void ins_beg();
void ins_end();
void ins_loc();
//node definition
struct node
{
    int info;
    struct node *link;
};
struct node *start=NULL;
//starting of main function
int main()
{
    int choice,choice1,choice2;
//function call for initiation of linked list
    create();
//creating MENU

    printf("\t\tMENU\n\n");
    printf("\t\t\t1.Traverse\n");
    printf("\t\t\t2.Insert\n");
    printf("\t\t\t3.deletion\n");
    printf("\t\t\t4.exit\n");
    printf("\tenter your choice:\n");
//taking input
    scanf("%d",&choice);
    switch(choice)
    {
//traversing
    case 1:
        printf("TRAVERSING\n");
        display();
        break;

//insertion
    case 2:
        printf("INSERTION\n");

        printf("\t\tenter your choice for insertion:\n");


        printf("\t\t\t1.insertion at beginning\n");

        printf("\t\t\t2.insertion at end\n");

        printf("\t\t\t3.insertion at location\n");

        printf("\t\t\t4.exit\n");

        scanf("%d",&choice1);
        switch(choice1)
        {
        case 1:
            printf("\nINSERTION AT THE BEGINNING\n");
            ins_beg();
            break;

        case 2:
            printf("\nINSERTION AT THE END\n");
            ins_end();
            break;

        case 3:
            printf("\nINSERTION AT THE LOCATION\n");
            printf("ENTER YOUR CHOICE FOR INSERTION AT LOCATION:\n");
            printf("\t1.INSERT ON THE LOCATION\n");
            printf("\t2.INSERT AFTER THE LOCATION\n");
            printf("\t3.EXIT\n");
            scanf("%d",&choice2);
            switch(choice2)
            {
            case 1:
                printf("INSERT ON THE LOCATION\n");
                ins_loc();
                break;

            case 2:
                printf("INSERT AFTER THE LOCATION\n");

                break;

            case 3:
                printf("EXITING\n");

            default:
                printf("!!invalid input!!\n");
                break;

            }
            break;

        case 4:
            printf("\nEXITING\n");
            exit(0);
            break;

        default:
            printf("\n!!!invalid input!!!\n");
            break;

        }
        break;

    case 3:
        printf("DELETION\n");
        break;

    case 4:
        printf("EXITING\n");
        break;

    default:
        printf("invalid input!!!\n");
        break;
    }

    return 0;
}
//function defintions

//function definition to initialize the linked list
void create()
{
    struct node *tmp,*ptr;
    int item;
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        tmp=(struct node*)malloc(sizeof(struct node));

        if(tmp==NULL)
        {
            printf("Memory Overflow!!!\n");
            exit(0);
        }
//taking the info value for the node from the user
        printf("enter the info value for the node:\n");
        scanf("%d",&item);
        tmp->info=item;

//checking whether there is one or more than one nodes already present in the linked list
        if(start==NULL)
        {
            start=tmp;
            tmp->link=NULL;
        }
        else
        {
            ptr=start;
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            ptr->link=tmp;
            tmp->link=NULL;
        }
//asking the user whether he wants to enter another node or not
        printf("want to create another node:y/n\n");
        scanf(" %c",&ch);
    }
}

//function to traverse the linked list
void display()
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("\t%d",ptr->info);
        ptr=ptr->link;
    }
}
//function to insert node at the beginning
void ins_beg()
{
    struct node *tmp;
    int item;
    char ch='y';
    while(ch=='y'||ch=='Y')
    {

        tmp=(struct node*)malloc(sizeof(struct node));
        if(tmp==NULL)
        {
            printf("Memory Overflow!!!\n");
            exit(0);
        }
//input of item in the tmp
        printf("enter the info for the node\n");
        scanf("%d",&item);
        tmp->info=item;

        if(start==NULL)
        {
            start=tmp;
            tmp->link=NULL;
        }
        else
        {
            tmp->link=start;
            start=tmp;
        }
        printf("want to enter another node at the beginning:y/n\n");
        scanf(" %c",&ch);
    }

    printf("the new linked list is:\n");
    display();
}
//function definition to insert node at the end of a linked list
void ins_end()
{
    struct node *tmp,*ptr;
    int item;
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        tmp=(struct node*)malloc(sizeof(struct node));
//taking input for info of the tmp
        printf("enter the info:\n");
        scanf("%d",&item);
        tmp->info=item;

        if(start==NULL)
        {
            start=tmp;
            tmp=NULL;
        }

        else
        {
            ptr=start;
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            ptr->link=tmp;
            tmp->link=NULL;
        }
        printf("want to enter another node at the end:y/n\n");
        scanf(" %c",&ch);
    }
    printf("the new linked list is:\n");
    display();

}

void ins_loc()
{
    struct node *ptr,*tmp;
    int i,item,loc;
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        if(tmp==NULL)
        {
            printf("memory overflow!!\n");
            exit(0);
        }
//taking input for info of tmp
        printf("enter the info value for the node:\n");
        scanf("%d",&item);
        tmp->info=item;
//taking input for the location
        printf("enter the location on which you want to enter the node:\n");
        scanf("%d",&loc);
        if(loc<=0)
        {
            printf("invalid input!!!");
        }

        if(start==NULL)
        {
            start=tmp;
            tmp->link=NULL;
        }
        else
        {
            ptr=start;
            for(i=1; i<loc; i++)
            {
                ptr=ptr->link;
                if(ptr==NULL)
                {
                    printf("node not available:\n");
                    exit(0)
                }
                else if(ptr->link==NULL)
                {
                    ptr->link=tmp;
                    tmp->link=NULL;
                }
                else
                {
                    tmp->link=ptr->link;
                    ptr->link=tmp;

                }


            }

        }

    }

}
