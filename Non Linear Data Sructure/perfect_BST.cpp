// To check whether given tree is perfect binary tree or not
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val):data(val),left(nullptr),right(nullptr) {}
    
};

Node* insert(int arr[], int n,int i){
    if(i<n){
        Node* root=new Node(arr[i]);
        root->left=insert(arr,n,2*i+1);
        root->right=insert(arr,n,2*i+2);
        return root;
    }
    return nullptr;
}

int findDepth(Node* node){
    int d=0;
    while(node != nullptr){
        d++;
        node=node->left;
    }
    return d;
}

bool check(Node* root, int d,int l=1){
    if(root==nullptr) return true;
    
    if(root->left==nullptr &&root->right==nullptr){
        return (d==l);
    }
    if(root->left==nullptr || root->right==nullptr){
        return false;
    }
    
    return check(root->left,d,l+1)&&check(root->right,d,l+1);
}

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    Node* root=insert(arr,n,0);
    int d=findDepth(root);
    
    if(check(root,d)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
    return 0;
}