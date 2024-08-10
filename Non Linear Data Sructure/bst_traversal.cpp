
// You are using GCC

#include<iostream>

using namespace std;

struct Node

{

    int data;

    Node* left;

    Node* right;

    Node(int val)

    {

        data = val;

        left = right = nullptr;

    }

};

Node* insert(Node* root, int val)

{

    if(root == nullptr)

    {

        return new Node(val);

    }

    if(val < root->data)

    {

        root->left = insert(root->left, val);

    }

    else

    {

        root->right = insert(root->right, val);

    }

    return root;

}

void inorder(Node* root)

{

    if(root != nullptr)

    {

        inorder(root->left);

        cout<<root->data<< " ";

        inorder(root->right);

    }

}
 
void preorder(Node* root)

{

    if(root != nullptr)

    {

        cout<<root->data<<" ";

        preorder(root->left);

        preorder(root->right);

    }

}
 
void postorder(Node* root)

{

    if(root != nullptr)

    {

        postorder(root->left);

        postorder(root->right);

        cout<<root->data<<" ";

    }

}

int main()

{

    int values[] = {38,13,51,10,12,40,84,25,89,37,66,95};

    int n = sizeof(values)/sizeof(values[0]);

    Node* root = nullptr;

    for(int i=0;i<n;i++)

    {

        root = insert(root, values[i]);

    }

    cout<<"Inorder traversal: ";

    inorder(root);

    cout<<endl;

    cout<<"preorder traversal: ";

    preorder(root);

    cout<<endl;

    cout<<"Postorder traversal: ";

    postorder(root);

    cout<<endl;

}