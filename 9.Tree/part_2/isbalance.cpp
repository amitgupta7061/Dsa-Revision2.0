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
    int f(TreeNode* root){
        if(!root) return 0;
        int leftH = f(root->left);
        if(leftH == -1) return -1;
        int rghtH = f(root->right);
        if(rghtH == -1) return -1;
        if(abs(leftH - rghtH) > 1) return -1;
        return 1 + max(leftH, rghtH);
    }
    bool isBalanced(TreeNode* root) {
        return f(root) != -1;
    }
};

int main() {

    return 0;
}