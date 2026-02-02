#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool f(TreeNode* p, TreeNode* q){
        if(p == NULL and q == NULL) return true;
        if(p == NULL or q == NULL)  return false;
        if(p->val != q->val) return false;
        return f(p->left, q->right) and f(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return f(root->left, root->right);
    }
};
int main() {

    return 0;
}