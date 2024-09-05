#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node* prev;
    
    node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

node* head = NULL;
node* curr = NULL;

void push(int data) {
    node* temp = new node(data);
    if (head == NULL) {
        head = temp;
        curr = temp;
    } else {
        curr->next = temp;
        temp->prev = curr;
        curr = curr->next;
    }
}

void reverse() {
    node* temp = head;
    node* newHead = NULL;
    
    // Traverse the list and swap next and prev pointers
    while (temp != NULL) {
        newHead = temp;  // Store the current node as the new head after reversal
        node* nextNode = temp->next;
        
        // Swap next and prev pointers
        temp->next = temp->prev;
        temp->prev = nextNode;
        
        // Move to the next node (which was originally the previous node)
        temp = nextNode;
    }
    
    // Update head to point to the new head (which is the old tail)
    head = newHead;
}

void print() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
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
