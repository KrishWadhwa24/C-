#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    int height;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
class AVLTree
{
    public:
    int height(node* root)
    {
        return root?root->height:0;
    }
    int balanceFactor(node* root)
    {
        return root?height(root->left)-height(root->right):0;
    }
    node* rightRotate(node* y)
    {
        node* x = y->left;
        node* T2 = x->right;
        x->right = y;
        y->left = T2;

        y->height = 1+ max(height(y->left),height(y->right));
        x->height = 1+ max(height(x->left),height(x->right));

        return x;
    }
    node* leftRotate(node* x)
    {
        node* y = x->right;
        node* T2 = y->left;

        y->left = x;
        x->right = T2;

        y->height = 1+ max(height(y->left),height(y->right));
        x->height = 1+ max(height(x->left),height(x->right));

        return y;
    }
    node* minValue(node* root)
    {
        node* curr = root;
        while(curr && curr->left !=NULL)
        curr = curr->left;
        return curr;
    }
    node* deleteNode(node* root,int key)
    {
        if(root==NULL)
        return root;

        if(key<root->data)
        root->left = deleteNode(root->left,key);
        else if(key>root->data)
        root->right = deleteNode(root->right,key);
        else
        {
            if(root->left==NULL)
            {
                node* temp = root->right;
                delete root;
                return temp;
            }else
            if(root->right==NULL)
            {
                node* temp = root->left;
                delete root;
                return temp;
            }else
            {
                node* temp = minValue(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right,temp->data);
            }
        }
        if(root==NULL)
        return root;

        root->height = 1+ max(height(root->left),height(root->right));
        int balance = balanceFactor(root);

        if(balance>1 && balanceFactor(root->left)>=0)
        return rightRotate(root);

        if(balance>1 && balanceFactor(root->left)<0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if(balance<-1 && balanceFactor(root->right)<=0)
        return leftRotate(root);

        if(balance<-1 && balanceFactor(root->right)>0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    void inorder(node* root)
    {
        if(root==NULL)
        return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};
int main()
{
    AVLTree tree;
    node* root = new node(9);
    root->left = new node(5);
    root->right = new node(10);
    root->left->left = new node(2);
    root->left->right = new node(6);
    root->right->right = new node(11);
    cout<<"Inorder traversal before deletion : ";
    tree.inorder(root);
    cout<<endl;
    root = tree.deleteNode(root,10);
    cout<<"Inorder traversal after deletion : ";
    tree.inorder(root);
    return 0;
}