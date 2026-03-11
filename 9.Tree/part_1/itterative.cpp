#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Iterative preorder traversal
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;   
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        result.push_back(node->val);
        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);
    }
    return result;
}

// Iterative inorder traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    TreeNode* current = root;
    while (current || !stk.empty()) {
        while (current) {
            stk.push(current);
            current = current->left;
        } 
        current = stk.top();
        stk.pop();
        result.push_back(current->val);
        current = current->right;
    }
    return result;
}

// iterative postorder traversal
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    stack<TreeNode*> stk1, stk2;
    stk1.push(root);
    while (!stk1.empty()) {
        TreeNode* node = stk1.top();
        stk1.pop();
        stk2.push(node);        
        if (node->left) stk1.push(node->left);
        if (node->right) stk1.push(node->right);
    }
    while (!stk2.empty()) {
        result.push_back(stk2.top()->val);
        stk2.pop();
    }
    return result;
}

// postorder traversal using single stack
vector<int> postorderTraversalSingleStack(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    stack<TreeNode*> stk;
    TreeNode* current = root;
    TreeNode* lastVisited = nullptr;
    while (current || !stk.empty()) {
        while (current) {
            stk.push(current);
            current = current->left;
        }
        TreeNode* peekNode = stk.top();
        if (peekNode->right && lastVisited != peekNode->right) {
            current = peekNode->right;
        } else {
            result.push_back(peekNode->val);        
            lastVisited = peekNode;
            stk.pop();
        }
    }
    return result;
}

int main() {

    return 0;
}