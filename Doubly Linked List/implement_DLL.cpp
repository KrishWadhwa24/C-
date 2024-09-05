#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* prev;
    public:
    node(int data)
    {
        this->data = data;
        next=NULL;
        prev=NULL;
    }
};
class DLL
{
    public:
    node* head;
    DLL()
    {
        head=NULL;
    }
    void insertAtTail(int data)
    {
        node* temp = new node(data);
        if(head==NULL)
        {
            head=temp;
            return;
        }
        node* temp1 = head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->prev=temp1;
    }
    void insertAtHead(int data)
    {
        node* temp = new node(data);
        if(head==NULL)
        {
            head=temp;
            return;
        }
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    void deleteAtHead()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        node* temp = head;
        head=head->next;
        head->prev=NULL;
        delete temp;
    }
    void deleteAtTail()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        node* temp = head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        node* temp1 = temp->next;
        temp->next=NULL;
        delete temp1;
    }
};
void print(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    DLL d;
    d.insertAtTail(1);
    d.insertAtTail(2);
    d.insertAtTail(3);
    d.insertAtTail(4);
    d.insertAtTail(5);
    d.insertAtHead(0);
    d.deleteAtTail();
    print(d.head);
    return 0;
}