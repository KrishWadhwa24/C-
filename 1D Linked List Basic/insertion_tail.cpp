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
        this->next = NULL;
    }
};
node* head=NULL;
node* curr=NULL;
void push(int data)
{
    if(head==NULL)
    {
        node* temp = new node(data);
        curr=temp;
        head = temp;
    }else
    {
        node* temp = new node(data);
        curr->next = temp;
        curr= curr->next;
    }
}
void print()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
int main()
{
    int x;
    cout<<"Enter the elements into the linked list: "<<endl;
    while(1)
    {
        cin>>x;
        if(x==-1)
        break;
        else
        {
            push(x);
        }
    }
    print();
}