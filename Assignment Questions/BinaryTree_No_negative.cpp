// To enter values for binary tree and break input loop as soon as a negative value is entered. Show Inorder Traversal
//left->root->rights
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(const vector<int>& nodes) {
    if (nodes.empty()) return NULL;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] > 0) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] > 0) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

void inOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

int main() {
    vector<int> nodes;
    int value;
    while (cin >> value && value > 0) {
        nodes.push_back(value);
    }
    TreeNode* root = createTree(nodes);
    inOrderTraversal(root);
    cout << endl;  // To ensure the output ends with a newline
    return 0;
}