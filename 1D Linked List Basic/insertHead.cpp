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
void push(int data,node* &head)
{
    node* temp = new node(data);
    temp->next = head;
    head=temp;
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
    node* head=NULL; 
    int x;
    
    cout<<"Enter the elements into the array : "<<endl;
    while(1)
    {
        cin>>x;
        if(x==-1)
        break;
        else
        {
            push(x,head);
        }
    }
    print(head);
}