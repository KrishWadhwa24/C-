#include<iostream>
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
node* head=NULL;
node* curr=NULL;
void push(int data)
{
    node* temp = new node(data);
    if(head==NULL)
    {
        head= temp;
        curr=temp;
        return;
    }else
    {
        curr->next=temp;
        curr=curr->next;
    }
}
void print()
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
void reverse()
{
    node* temp = head;
    node* prev=NULL;
    while(temp!=NULL)
    {
        node* front = temp->next;
        temp->next=prev;
        prev = temp;
        temp=front;
    }
    head = prev;
}
int main()
{
    int x;
    cout << "Enter the elements into the linked list:" << endl;
    while (1) {
        cin >> x;
        if (x == -1)
            break;
        else
            push(x);
    }
    
    cout << "Original List: ";
    print();
    
    reverse();
    
    cout << "Reversed List: ";
    print();
    
    return 0;
}
