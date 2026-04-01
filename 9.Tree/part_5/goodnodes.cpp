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
    int f(TreeNode* root, int maxi){
        if(!root) return 0;
        int cnt = 0;
        if(root->val >= maxi)
            cnt = 1;
        maxi = max(maxi, root->val);
        return cnt + f(root->left, maxi) + f(root->right, maxi);
    }
    int goodNodes(TreeNode* root) {
        return f(root, root->val);
    }
};

int main() {

    return 0;
}