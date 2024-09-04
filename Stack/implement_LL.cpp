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
class stack
{
    public:
    node* top;
    int size;
    stack()
    {
        top=NULL;
        size= 0;
    }
    void push(int data)
    {
        node* temp = new node(data);
        temp->next = top;
        top = temp;
        size++;
    }
    void pop()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty\n";
            return;
        }
        node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int top1()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty\n";
            return -1;
        }
        return top->data;
    }
    int Size()
    {
        return size;
    }
    bool isEmpty()
    {
        return top==NULL;
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top1()<<endl;
    s.pop();
    cout<<s.top1()<<endl;
    cout<<s.isEmpty()<<endl;
    s.pop();
    s.pop();
    cout<<s.isEmpty()<<endl;
    return 0;
}