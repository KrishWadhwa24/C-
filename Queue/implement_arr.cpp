#include<iostream>
using namespace std;
class queue
{
    public:
    int front;
    int rear;
    int size;
    int *arr;
    queue(int size)
    {
        front=-1;
        rear=-1;
        this->size = size;
        arr= new int[size];
    }
    void push(int data)
    {
        if(rear==size-1)
        {
            cout<<"Queue is full\n";
            return;
        }
        arr[++rear]=data;
        if(front==-1)
        {
            front++;
        }
    }
    void pop()
    {
        if(front==-1||front>rear)
        {
            cout<<"Queue is empty\n";
            return;
        }
        front++;
    }
    int front1()
    {
        if(front==-1||front>rear)
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
    bool isEmoty()
    {
        return front==-1||front>rear;
    }
};
int main()
{
    queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<q.front1()<<endl;
    q.pop();
    cout<<q.front1()<<endl;
    q.pop();
    cout<<q.front1()<<endl;
    q.pop();
    return 0;
}
