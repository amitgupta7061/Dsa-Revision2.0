#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// preorder, inorder and postorder traversal in one pass
void allTraversals(TreeNode* root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder) {
    if (!root) return;
    stack<pair<TreeNode*, int>> stk;
    stk.push({root, 1});    

    while (!stk.empty()) {
        auto [node, state] = stk.top();
        stk.pop();
        
        if (state == 1) {
            preorder.push_back(node->val);
            stk.push({node, 2});
            if (node->left) stk.push({node->left, 1});
        } 
        else if (state == 2) {
            inorder.push_back(node->val);
            stk.push({node, 3});
            if (node->right) stk.push({node->right, 1});
        } 
        else {
            postorder.push_back(node->val);
        }
    }
}

int main() {

    return 0;
}