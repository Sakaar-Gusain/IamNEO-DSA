// binary tree with inorder traversal

#include<iostream>

using namespace std;

class TreeNode
{
    public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        value = val;
        left = nullptr;
        right = nullptr;
    }

};

//Function to insert value into BST

TreeNode* insertIntoBST(TreeNode* root, int value){
    //if the tree is empty, create a new node as root node
    if(root == nullptr){
        return new TreeNode(value);
    }

    //Insert into the left subtree if value is less than root's value

    if(value < root->value){
        root->left = insertIntoBST(root->left, value);
    }

    // else if(value > root->value)

    // {

    //     root->right = insertIntoBST(root->right, value);

    // }

    else

    {

        root->right = insertIntoBST(root->right, value);

    }

    return root;

}

//Fuction tp perform inorder traversal of BST

void inorderTraversal(TreeNode* root)

{

    if(root != nullptr)

    {

        inorderTraversal(root->left);

        cout<<root->value<<" ";

        inorderTraversal(root->right);

    }

}

int main()

{

    TreeNode* root = nullptr;

    int values[] = {11,6,8,19,4,10,5,17,43,49,31};

    int n = sizeof(values) / sizeof(values[0]);

    //Inserting into BST

    for(int i=0;i<n;i++)

    {

        root = insertIntoBST(root, values[i]);

    }

    //print the inorder traversal of BST

    cout<<"Inorder traversal of the BST:"<< endl;

    inorderTraversal(root);

    cout<<endl;

}