// To enter size and elements in trea and find it's max depth
#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

Node* insert(Node* root, int data){
    if(root==NULL){
        return create(data);
    }
    
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

int maxDepth(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int leftD=maxDepth(root->left);
        int rightD=maxDepth(root->right);
        return max(leftD,rightD)+1;
    }
}

int main(){
    int n;
    cin>>n;
    Node* root=NULL;
    int v;
    for(int i=0;i<n;i++){
        cin>>v;
        root=insert(root,v);
    }
    int d=maxDepth(root);
    cout<<d<<endl;
    return 0;
}