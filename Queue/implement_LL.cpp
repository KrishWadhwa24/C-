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
class queue
{
    public:
    node* front;
    node* rear;
    int size;
    queue()
    {
        front=NULL;
        rear=NULL;
        size=0;
    }
    void enqueue(int data)
    {
        node* temp = new node(data);
        if(front==NULL)
        {
            front=temp;
            rear = temp;
        }else
        {
            rear->next = temp;
            rear= rear->next;
        }
        size++;
    }
    void dequeue()
    {
        if(front==NULL)
        {
            cout<<"Queue is empty\n";
            return;
        }
        node* temp = front;
        front = front->next;
        delete temp;
        size--;
    }
    int front1()
    {
        if(front==NULL)
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        return front->data;
    }
    bool isEmpty()
    {
        return front==NULL;
    }
};
int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout<<q.front1()<<endl;
    q.dequeue();
    cout<<q.front1()<<endl;
    q.dequeue();
    cout<<q.front1()<<endl;
    q.dequeue();
    return 0;
}