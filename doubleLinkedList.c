#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node*llink,*rlink;
}n;

void display(n*head)
{
    n*x;
    x=head;
    if(head==NULL)
    {
        printf("the list is empty");
    }
    else
    {
        while(x!=NULL)
        {
            printf("%d ",x->info);
            x=x->rlink;
        }
    }
}

void search(n*head)
{
    n*x;
    int num;
    x=head;
    if(head==NULL)
    {
        printf("the list is empty");
    }
    else
    {
        printf("enter the info you want to search:");
        scanf("%d",&num);
        while(x!=NULL)
        {
            if(num==x->info)
            {
                printf("the info is present in the list");
                break;
            }
            x=x->rlink;
        }
        if(x==NULL)
        {
            printf("the info is not present in the list");
        }
    }
}

n*insertfor(n*head)
{
    n*x,*ptr;
    x=head;
    ptr=(n*)malloc(sizeof(n));
    printf("enter the info:");
    scanf("%d",&ptr->info);
    ptr->rlink=ptr->llink=NULL;
    ptr->rlink=x;
    x->llink=ptr;
    head=ptr;
    return head;
}

n*insertend(n*head)
{
    n*x,*ptr;
    x=head;
    ptr=(n*)malloc(sizeof(n));
    printf("enter the info:");
    scanf("%d",&ptr->info);
    ptr->llink=ptr->rlink=NULL;
    while(x->rlink!=NULL)
    {
        x=x->rlink;
    }
    x->rlink=ptr;
    ptr->llink=x;
    return head;

}

n*deletefor(n*head)
{
    n*x;
    x=head;
    if(head==NULL)
    {
        printf("the list is empty");
    }
    else
    {
        head=head->rlink;
        free(x);
        head->llink=NULL;
    }
    return head;
}

n*deleteend(n*head)
{
    n*x,*y;
    x=head;
    if(head==NULL)
    {
        printf("the list is empty");
    }
    else if(head->rlink==NULL)
    {
        printf("the delete is not posible");
    }
    else
    {
        while(x->rlink!=NULL)
        {
            y=x;
            x=x->rlink;
        }
        free(x);
        y->rlink=NULL;
        return head;
    }
}

n*insert(n*head)
{
    n*x,*ptr;
    int pos,i=1,count=0;
    x=head;
    printf("enter the position you want to insert:");
    scanf("%d",&pos);
    if(pos == 1)
    {
        ptr=(n*)malloc(sizeof(n));
        printf("enter the info:");
        scanf("%d",&ptr->info);
        ptr->llink=ptr->rlink=NULL;
        ptr->rlink = head;
        head ->llink = ptr;
        head = ptr;
        return head;
    }
    while(x!=NULL)
    {
        x=x->rlink;
        count++;
    }
    if(pos+1>count)
    {
        printf("invalid position");
    }
    else
    {
        x=head;
        ptr=(n*)malloc(sizeof(n));
        printf("enter the info:");
        scanf("%d",&ptr->info);
        ptr->llink=ptr->rlink=NULL;
        while(i!=pos)
        {
            x=x->rlink;
            i++;
        }
        ptr->rlink=x;
        ptr->llink=x->llink;
        (x->llink)->rlink=ptr;
        x->llink=ptr;
    }
    return head;
}

n*delete(n*head)
{
    n*x,*y;
    int pos,i=1,count=0;
    x=head;
    printf("enter the position:");
    scanf("%d",&pos);
    if(pos == 1)
    {
        head = head -> rlink;
        free(x);
        head ->llink = NULL;
        return head;
    }
    while(x!=NULL)
    {
        x=x->rlink;
        count++;
    }
    if(pos>count)
    {
        printf("invalid position");
        return head;
    }
    if(pos == count)
    {
        x= head;
        while(x->rlink != NULL)
        {
            y=x;
            x= x->rlink;
        }
        y->rlink = x->rlink;
        x->llink = NULL;
        free(x);
        return head;
    }
    x=head;
    while(i < pos)
    {
        y=x;
        x=x->rlink;
        i++;
    }
    y->rlink=x->rlink;
    (x->rlink)->llink=y;
    free(x);
    return head;
}

n*insertbeData(n*head)
{
    n*x,*ptr;
    int num;
    x=head;
    if(head==NULL)
    {
        printf("the list is empty");
    }
    else{
        printf("enter the data before you want to insert:");
        scanf("%d",&num);
        ptr=(n*)malloc(sizeof(n));
        while(x != NULL)
        {
            if(x-> info == num)
            {
                break;
            }
            x=x->rlink;
            if(x == NULL)
            {
                printf("the data is not present in the list\n");
                return head;
            }
        }
        x= head;
        printf("enter the info:");
        scanf("%d",&ptr->info);
        ptr->llink=ptr->rlink=NULL;

        if(head ->info == num)
        {
            ptr->rlink = head;
            head -> llink = ptr;
            head = ptr;
            return head;
        }
        while(x->info!=num)      
        {
            x=x->rlink;
        }
        ptr->rlink=x;
        ptr->llink=x->llink;
        (x->llink)->rlink=ptr;
        x->llink=ptr;

    }
    return head;
}

n*insertafData(n*head)
{
    n*x,*ptr;
    int num;
    x=head;
    if(head==NULL)
    {
        printf("the list is empty");
    }
    else
    {
        printf("enter the data after you want to insert:");
        scanf("%d",&num);
        ptr=(n*)malloc(sizeof(n));
         while(x != NULL)
        {
            if(x-> info == num)
            {
                break;
            }
            x=x->rlink;
            if(x == NULL)
            {
                printf("the data is not present in the list");
                return head;
            }
        }
        x= head;
        printf("enter the info:");
        scanf("%d",&ptr->info);
        ptr->rlink=ptr->llink=NULL;
        while(x->info!=num)
        {
            x=x->rlink;
        }
        if(x -> rlink == NULL)
        {
            ptr->rlink = x->rlink;
            x->rlink = ptr;
            ptr->llink = x;
            return head;
        }
        ptr->rlink= x->rlink;
        ptr->llink=x;
        (x->rlink)->llink=ptr;
        x->rlink=ptr;
    }
    return head;
}

n*deletebeData(n*head)
{
    if(head==NULL)
    {
        printf("the list is empty");
    }
    n*x,*a;
    int data;
    printf("enter the data:");
    scanf("%d",&data);
    x=head;
     while(x != NULL)
        {
            if(x-> info == data)
            {
                break;
            }
            x=x->rlink;
            if(x == NULL)
            {
                printf("the data is not present in the list");
                return head;
            }
        }
        x= head;
    if(head->info==data)
    {
        printf("delete is not posible");
    }
    else if((head->rlink)->info==data)
    {
        head=head->rlink;
        free(x);
    }
    else
    {
        x=head;
        while(x!=NULL)
        {
            if(x->info==data)
            {
                break;
            }
            x=x->rlink;
            if(x==NULL)
            {
                printf("the data is not in the list");
            }
        }
        x=head;
        while(x->info!=data)
        {
            a=x;
            x=x->rlink;
        }
        (a->llink)->rlink=x;
        x->llink=a->llink;
        free(a);
        }
    return head;
    
}

n*deleteafData(n*head)
{
   if (head==NULL)
    {
        printf("\nEmpty List!\n");
        return head;
    }
    else if (head->rlink==NULL)
    {
        printf("delete not possible!\n");
        return head;
    }
    n *x=head, *a, *b;
    int data;
    printf("Enter a data after you want to delete a node: ");
    scanf("%d", &data);
    while (x!=NULL)
    {
        if (x->info==data)
            break;
        x=x->rlink;
        if (x==NULL)
        {
            printf("\nDeletion Not Possible!\n");
            return head;
        }
    }
    x=head;
    b=head;
    while (x!=NULL && b!=NULL)
    {
        a=x;
        x=x->rlink;
        b=x->rlink;
        if (a->info==data)
        {
            if (b==NULL)
            {
                a->rlink=NULL;
                free(x);
                return head;
            }
            a->rlink=b;
            b->llink=a;
            free(x);
            return head;
        }
    }
    if (a->info==data)
    {
        a->rlink=NULL;
        free(x);
        return head;
    }
    else if (x->info==data)
    {
        printf("\nDeletion Not Possible!\n");
        return head;
    }
    if(a->info==data)
    {
        a->rlink=NULL;
        free(x);
    }
    else if(x->info==data)
    {
        printf("delete is not posible");
    }
    return head;
}

int main(){
    n*head=NULL,*ptr,*current;
    int ch,ans;
    while(1){
        
        ptr=(n*)malloc(sizeof(n));
        printf("enter the info:");
        scanf("%d",&ptr->info);
        ptr->rlink=ptr->llink=NULL;
        if(head==NULL)
        {
            head=ptr;
            current=ptr;
        }
        else
        {
            current->rlink=ptr;
            ptr->llink=current;
            current=current->rlink;
        }
        printf("do you want to continue(1/0)?:");
        scanf("%d",&ans);
        if(ans==0)
        {
            break;
        }
    }
    while(1)
    {
        printf("\n1.display\n2.search\n3.insert at the begening\n4.insert at the end\n5.delete at the begening\n");
        printf("6.delete  at the end\n7.insert at any position\n8.delete any position\n9.insert before data\n10.insert after the data\n");
        printf("11.delete before data\n12delete after data\n13.exit\n");
        printf("enter your choise:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:display(head);
                break;
            case 2:search(head);
                break;
            case 3:head=insertfor(head);
                break;
            case 4:head=insertend(head);
                break;
            case 5:head=deletefor(head);
                break;
            case 6:head=deleteend(head);
                break;
            case 7:head=insert(head);
                break;
            case 8:head=delete(head);
                break;
            case 9:head=insertbeData(head);
                break;
            case 10:head=insertafData(head);
                break;
            case 11:head=deletebeData(head);
                break;
            case 12:head=deleteafData(head);
                break;
            case 13:exit(0);
                break;
            default:
                printf("invalid choice");
        }
    }
}

