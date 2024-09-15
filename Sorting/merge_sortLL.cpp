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

node* findMiddle(node* head)
{
    node* slow = head;
    node* fast = head->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node* merge(node* head1,node* head2)
{
    node* dummy = new node(-1);
    node* temp = dummy;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            temp->next = head1;
            head1=head1->next;
            temp = temp->next;
        }else
        {
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;  
        }
    }
    if(head1)
    {
        temp->next = head1;
    }
    if(head2)
    {
        temp->next = head2;
    }
    return dummy->next;
}
node* mergeSort(node* head)
{
    if(head==NULL||head->next==NULL)
    return head;

    node* middle = findMiddle(head);
    node* leftHead = head;
    node* rightHead = middle->next;
    middle->next = NULL;
    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);
    return merge(leftHead,rightHead);
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
    head = mergeSort(head);
    cout<<"The sorted linked list is\n";
    print(head);
    return 0;
}