/*Given an empty AVL tree and a series of integer values, implement the insertion of these values into the AVL tree and then perform a pre-order traversal to display the elements.

Input format :
The first line of input consists of the number of nodes in the AVL Tree, N.

The second line of input consists of the nodes of the AVL Tree, separated by space.

Output format :
The output prints the pre-order traversal of the constructed AVL Tree, separated by space.

7
4 5 8 11 12 17 18 

output:
11 5 4 8 17 12 18 
*/
#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    
    int height;
};

int H(Node* N){
    if(N==nullptr){
        return 0;
    }
    return N->height;
}

int M(int a, int b){
    return (a>b)?a:b;
}

Node* newNode(int key){
    Node* node=new Node();
    node->key=key;
    node->left=nullptr;
    node->right=nullptr;
    node->height=1;
    return node;
}

Node* RR(Node* y){
    Node*x=y->left;
    Node* T2=x->right;
    
    x->right=y;
    y->left=T2;
    
    y->height=max(H(y->left),H(y->right)) +1;
    x->height=max(H(x->left),H(x->right))+1;
    
    return x;
}

Node* LR(Node* x){
    Node*y=x->right;
    Node* T2=y->left;
    
    y->left=x;
    x->right=T2;
    
    x->height=max(H(x->left),H(x->right))+1;
    y->height=max(H(y->left),H(y->right))+1;
    
    return y;
}

int getB(Node* N){
    if(N==nullptr)
        return 0;
    return H(N->left)-H(N->right);
}

Node* insert(Node* node, int key){
    if(node==nullptr){
        return (newNode(key));
    }
    
    if(key<node->key){
        node->left=insert(node->left,key);
    }
    else if(key>node->key){
        node->right=insert(node->right,key);
    }
    else{
        return node;
    }
    
    node->height=1+max(H(node->left), H(node->right));
    
    int bal=getB(node);
    
    if(bal>1&& key<node->left->key)
        return RR(node);
    
    if(bal<-1 && key>node->right->key)
        return LR(node);
        
    if(bal>1 &&key>node->left->key){
        node->left=LR(node->left);
        return RR(node);
    }
    
    if(bal<-1 && key<node->right->key){
        node->right=RR(node->right);
        return LR(node);
    }
    
    return node;
}

void preOrder(Node* root){
    if(root != nullptr){
        cout<<root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    Node* root=nullptr;
    
    int n;
    cin>>n;
    vector<int> N(n);
    for(int i=0;i<n;i++){
        cin>>N[i];
    }
    
    for(int key: N){
        root=insert(root,key);
    }
    preOrder(root);
    cout<<endl;
    return 0;
}