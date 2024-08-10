/*Write a program to create a Binary Search Tree and perform recursive traversals.
inorder
preorder
postorder*/
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

//inserting values to node
Node* insert(Node* root, int key){
    if(root==nullptr){
        return new Node(key);
    }
    if(key<root->data){
        root->left=insert(root->left, key);
    }
    else if(key>root->data){
        root->right=insert(root->right, key);
    }
    else{
        cout<<"Duplicate value not allowed"<<endl;
    }
    return root;
}

//Inorder traversal left->root->right
void inOrder(Node* root){
    if(root != nullptr){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

//preorder traversals root->left->right
void preOrder(Node* root){
    if(root != nullptr){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


//postOrder treaversals left->right->root
void postOrder(Node* root){
    if(root != nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    Node* root =nullptr;
    int c;
    
    while (true){
        cin>>c;
        
        switch(c){
            case 1:
                int n;
                cin>>n;
                
                for(int i=0;i<n;i++){
                    int e;
                    cin>>e;
                    root=insert(root,e);
                }
                cout<<"BST with "<<n<<" nodes is ready to use"<<endl;
                break;
                
            case 2:
                cout<<"BST Traversal in INORDER"<<endl;
                inOrder(root);
                cout<<endl;
                break;
                
            case 3:
                cout<<"BST Traversal in PREORDER"<<endl;
                preOrder(root);
                cout<<endl;
                break;
                
            case 4:
                cout<<"BST Traversal in POSTORDER"<<endl;
                postOrder(root);
                cout<<endl;
                break;
                
            case 5:
                return 0;
            default:
                cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}