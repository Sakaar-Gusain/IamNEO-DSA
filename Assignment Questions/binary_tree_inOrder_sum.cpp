/*Write a program to replace each node in a binary tree with the sum of its in-order predecessor 
and successor.
Example:
Input 
7
1
2 3 4 5 6 7

Output 
Before tree modification:
1 2 4 5 3 6 7 
After tree modification:
11 9 2 3 13 4 3 

Explanation:
Before the tree modification, the preorder traversal of the original tree gave the node values as 
1 2 4 5 3 6 7. Now, let's understand how the replacement of each node with the sum of its in-order 
predecessor and successor works: We perform an in-order traversal of the original tree to obtain 
the in-order sequence of node values: 4 2 5 1 3 6 7. For each node in the tree, we replace its 
value with the sum of its in-order predecessor and successor values. 
The in-order predecessor and successor for each node are determined based on the in-order sequence 
obtained in step 1. 
The modified tree becomes:11 9 2 3 13 4 3 */

// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int v):data(v),left(nullptr), right(nullptr){}
    
};

Node* insert(vector<int>& v, int n, int i){
    if(i<n){
        Node* root=new Node(v[i]);
        root->left=insert(v,n,2*i+1);
        root->right=insert(v,n,2*i+2);
        return root;
    }
    return nullptr;
}

void preOrder(Node* root){
    if(root != nullptr){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root, vector<int>& v){
    if(root !=nullptr){
        inOrder(root->left,v);
        v.push_back(root->data);
        inOrder(root->right,v);
    }
}

void modify(Node* root, const vector<int>& v){
    static int index=0;
    if(root != nullptr){
        modify(root->left, v);
        int p=(index ==0)?0:v[index-1];
        int s=(index==v.size()-1)?0: v[index+1];
        
        root->data=p+s;
        index++;
        
        modify(root->right,v);
    }
}

void resetIndex(){
    static int& index=* new int;
    index=0;
}

int main(){
    int n;
    cin>>n;
    
    vector<int> v(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    Node* root=insert(v,n,0);
    
    cout<<"Before tree modification:"<<endl;
    preOrder(root);
    cout<<endl;
    
    vector<int> m;
    inOrder(root,m);
    resetIndex();
    modify(root,m);
    
    cout<<"After tree modification:"<<endl;
    preOrder(root);
    cout<<endl;
    
    return 0;
}

