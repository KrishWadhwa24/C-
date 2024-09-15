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
        next = NULL;
    }
};
node* bubble_sort(node* head)
{
    if(head==NULL||head->next==NULL)
    return head;
    node* temp = head;
    while(temp!=NULL)
    {
        node* temp1 = head;
        while(temp1->next!=NULL)
        {
            if(temp1->data>temp1->next->data)
            {
                int temp2 = temp1->data;
                temp1->data = temp1->next->data;
                temp1->next->data = temp2;
            }
            temp1 = temp1->next;
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
    head = bubble_sort(head);
    cout<<"The sorted linked list is\n";
    print(head);
    return 0;
}