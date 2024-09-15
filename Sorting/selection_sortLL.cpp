#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data = data;
        next=NULL;
    }
};
node* selectionSort(node* head)
{
    node* temp = head;
    while(temp)
    {
        node* mini = temp;
        node* r = temp->next;
        while(r)
        {
            if(r->data<mini->data)
            {
                mini = r;
            }
            r = r->next;
        }
        if(mini!=temp)
        {
            int x= temp->data;
            temp->data = mini->data;
            mini->data = x;
        }
        temp = temp->next;
    }
    return head;
}
void print(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main()
{
    int n;
    cin>>n;
    node* head = NULL;
    node* tail = NULL;
    cout<<"Enter the elements of the linked list\n";
    for(int i = 0;i<n;i++)
    {
        int data;
        cin>>data;
        node* newnode = new node(data);
        if(head==NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    head = selectionSort(head);
    cout<<"The sorted linked list is\n";
    print(head);
    return 0;
}