#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode 
{
    public : 
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) 
    {
        this -> val = val;
        left = NULL;
        right = NULL;
    }
};

long long ans = -1;

long long dfs(TreeNode<int>* root) {
    if (!root) return 0;

    if (!root->left && !root->right)
        return root->val;

    long long left = dfs(root->left);
    long long right = dfs(root->right);

    if (root->left && root->right) {
        ans = max(ans, left + right + root->val);
        return root->val + max(left, right);
    }

    return root->val + (root->left ? left : right);
}

long long int findMaxSumPath(TreeNode<int> *root) {
    ans = -1;
    dfs(root);
    return ans;
}