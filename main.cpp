#include <iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* create(int size)
{
    struct node* head;
    head=NULL;
    for(int i=0;i<size;i++)
    {
        int data;
        cout<<"Enter data in linked  list"<<endl;
        cin>>data;
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            struct node* ptr;
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }
    return head;
}
void traverse(struct node* head)
{
    if(head==NULL)
    {
        cout<<"Nothing to show"<<endl;
    }
    else{
        cout<<"Linked list data"<<endl;
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
    }
}
bool find(struct node* head,int x,int y)
{
    int flag=0;
    while(head!=NULL)
    {
        if(head->data==x || head->data==y)
        {
            flag++;
        }
        head=head->next;
    }
    if(flag==2)
    {
        return true;
    }
    return false;
}
struct node* swapnodes(struct node* head)
{
    int x,y;
    cout<<"Enter two number who's nodes have to be swapped"<<endl;
    cin>>x>>y;
    if(find(head,x,y))
    {
       struct node *prevX = NULL, *currX = head;
       while (currX && currX->data != x)
       {
           prevX = currX;
           currX = currX->next;
       }
       struct node *prevY = NULL, *currY = head;
       while (currY && currY->data != y)
       {
           prevY = currY;
           currY = currY->next;
       }
       if (prevX != NULL)
           prevX->next = currY;
       else
           head = currY;
       if (prevY != NULL)
           prevY->next = currX;
       else
           head = currX;
       struct node *temp = currY->next;
       currY->next = currX->next;
       currX->next  = temp;
    }
    else{
        cout<<"Values not present"<<endl;
    }
    return head;
}
int main()
{
    struct node* head=NULL;
    int size;
    cout<<"Enter size of linked list"<<endl;
    cin>>size;
    head=create(size);
    head=swapnodes(head);
    traverse(head);

    return 0;
}
