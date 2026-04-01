#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.
// The length of the path between two nodes is represented by the number of edges between them.

class Solution {
public:
    int f(TreeNode* root, int &ans) {
        if(!root) return 0;
        int left = f(root->left, ans);
        int right = f(root->right, ans);
        int leftAns = 0, rightAns = 0;
        if(root->left && root->left->val == root->val)
            leftAns = left + 1;
        if(root->right && root->right->val == root->val)
            rightAns = right + 1;
        ans = max(ans, leftAns + rightAns);
        return max(leftAns, rightAns);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        f(root, ans);
        return ans;
    }
};

int main() {

    return 0;
}