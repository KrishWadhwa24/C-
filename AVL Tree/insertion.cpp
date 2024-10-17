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
        this->data=data;
        left=NULL;
        right=NULL;
        height=1;
    }
};
class AVLTree
{
    public:
    int height(node* root)
    {
        return root?root->height:0;
    }
    node* rightRotate(node* y){
        node* x = y->left;
        node* T2 = x->right;
        x->right = y;
        y->left = T2;

        y->height = 1+max(height(y->left),height(y->right));
        x->height = 1+max(height(x->left),height(x->right));
        return x;
    }
    node* leftRotate(node* x)
    {
        node* y = x->right;
        node* T2 = y->left;
        y->left = x;
        x->right = T2;

        x->height = 1+max(height(x->left),height(x->right));
        y->height = 1+max(height(y->left),height(y->right));

        return y;
    }

    int getBalance(node* root)
    {
        return root?height(root->left)-height(root->right):0;
    }
    node* insert(node* root,int key)
    {
        if(root==NULL)
        return new node(key);

        if(key<root->data)
        root->left = insert(root->left,key);
        else if(key>root->data)
        root->right = insert(root->right,key);
        else
        return root;

        root->height = 1+max(height(root->left),height(root->right));
        int balance = getBalance(root);

        if(balance>1 && key<root->left->data)
        return rightRotate(root);

        if(balance<-1 && key>root->right->data)
        return leftRotate(root);

        if(balance>1 && key>root->left->data)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if(balance<-1 && key<root->right->data)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    node* inorder(node* root)
    {
        if(root==NULL)
        return root;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};
int main()
{
    AVLTree tree;
    node* root = NULL;
    root = tree.insert(root,10);
    root = tree.insert(root,20);
    root = tree.insert(root,30);
    root = tree.insert(root,40);
    root = tree.insert(root,50);
    root = tree.insert(root,25);
    cout<<"Inorder traversal of the constructed AVL tree is : ";
    tree.inorder(root);
    return 0;
}