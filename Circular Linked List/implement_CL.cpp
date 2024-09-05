#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data= data;
        next=NULL;
    }
};
class circular
{
    public:
    node* head;
    node* curr;
    circular()
    {
        head=NULL;
        curr=NULL;
    }
    void insertTail(int data)
    {
        node* temp = new node(data);
        if(head==NULL)
        {
            head= temp;
            curr= temp;
            curr->next=head;
            return;
        }
        curr->next= temp;
        curr= curr->next;
        curr->next=head;
    }
    void insertHead(int data)
    {
        node* temp = new node(data);
        if(head==NULL)
        {
            head= temp;
            curr= temp;
            curr->next=head;
            return;
        }
        temp->next = head;
        head=temp;
        curr->next=head;
    }
    void deleteHead()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        node* temp = head;
        head= head->next;
        curr->next = head;
        delete temp;
    }
    void deleteTail()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        node* temp = head;
        while(temp->next!=curr)
        {
            temp=temp->next;
        }
        node* temp1=curr;
        temp->next = head;
        curr=temp;
        delete temp1;
    }
    int length()
    {
        int count=0;
        node* temp = head;
        while(temp!=curr)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    void insertKth(int data,int k)
    {
        node *temp= new node(data);
        if(k>length())
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        if(k==1)
        insertHead(data);
        else
        if(k==length())
        insertTail(data);
        else{
            node* temp1=head;
            for(int i =1;i<k-1;i++)
            {
                temp1=temp1->next;
            }
            temp->next=temp1->next;
            temp1->next=temp;
        }
    }
    void deleteKth(int k)
    {
         if(k>length())
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        if(k==1)
        deleteHead();
        else
        if(k==length())
        deleteTail();
        else{
            node *temp1=head;
            for(int i=1;i<k-1;i++)
            {
                temp1=temp1->next;
            }
            node* temp = temp1->next;
            temp1->next=temp->next;
            delete temp;
        }
    }
};
int main()
{
    circular c;
    int x;
    cout << "Enter the elements into the linked list:" << endl;
    while (1) {
        cin >> x;
        if (x == -1)
            break;
        else
            c.insertTail(x);
    }
    cout << "Original List: ";
    node* temp = c.head;
    while(temp!=c.curr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    cout<<"Length of the list is: "<<c.length()<<endl;
    cout<<"Enter the element to be inserted at head: ";
    cin>>x;
    c.insertHead(x);
    cout<<"List after inserting at head: ";
    temp = c.head;
    while(temp!=c.curr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    cout<<"Length of the list is: "<<c.length()<<endl;
    cout<<"Enter the element to be inserted at tail: ";
    cin>>x;
    c.insertTail(x);
    cout<<"List after inserting at tail: ";
    temp = c.head;
    while(temp!=c.curr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    cout<<"Length of the list is: "<<c.length()<<endl;
    cout<<"Enter the position and element to be inserted: ";
    int k;
    cin>>k>>x;
    c.insertKth(x,k);
    cout<<"List after inserting at position "<<k<<": ";
    temp = c.head;
    while(temp!=c.curr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    cout<<"Length of the list is: "<<c.length()<<endl;
    cout<<"Enter the position to be deleted: ";
    cin>>k;
    c.deleteKth(k);
    cout<<"List after deleting at position "<<k<<": ";
    temp = c.head;
    while(temp!=c.curr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    cout<<"Length of the list is: "<<c.length()<<endl;
    return 0;
}