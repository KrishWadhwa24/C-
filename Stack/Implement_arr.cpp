#include<iostream>
using namespace std;
class stack
{
    public:
    int *arr;
    int top;
    int capacity;
    public:
    stack(int size)
    {
        this->capacity = size;
        top = -1;
        arr = new int[capacity];
    }
    void push(int data)
    {
        if(top==capacity-1)
        {
            cout<<"Stack is full\n";
            return;
        }
        arr[++top]=data;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty\n";
            return;
        }
        top--;
    }
    int Top()
    {
        if(top==-1)
        {
            cout<<"Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        return top==-1;
    }
};
int main()
{
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.Top()<<endl;
    s.pop();
    cout<<s.Top()<<endl;
    cout<<s.isEmpty()<<endl;
    s.pop();
    s.pop();
    cout<<s.isEmpty()<<endl;
    return 0;
}