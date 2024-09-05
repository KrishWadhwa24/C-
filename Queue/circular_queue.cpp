#include<iostream>
using namespace std;
class queue
{
    public:
    int front;
    int rear;
    int size;
    int* arr;
    queue(int size)
    {
        front=-1;
        rear=-1;
        this->size=size;
        arr=new int[size];
    }
    int isFull()
    {
        if((front>rear)||(front==0 && rear==size-1))
        {
            return 1;
        }
        return 0;
    }
    void enqueue(int data)
    {
        if(isFull())
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        if(front==-1)
        {
            front=0;
        }
        rear=(rear+1)%size;
        arr[rear]=data;
    }
    int isEmpty(){
        if(front==-1)
        {
            return 1;
        }
        return 0;
    }
    int dequeue(){
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int data = arr[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }else
        {
            front=(front+1)%size;
        }
        return data;
    }
};
int main()
{
    int size;
    cout<<"Enter the size of the queue"<<endl;
    cin>>size;
    queue q(size);
    int x;
    cout<<"Enter the elements into the queue"<<endl;
    while(1)
    {
        cin>>x;
        if(x==-1)
        {
            break;
        }else
        {
            q.enqueue(x);
        }
    }
    cout<<"Dequeue elements from the queue"<<endl;
    while(!q.isEmpty())
    {
        cout<<q.dequeue()<<" ";
    }
    cout<<endl;
    return 0;
}