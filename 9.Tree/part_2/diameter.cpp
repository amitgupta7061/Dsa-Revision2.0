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
    int f(TreeNode* root, int &maxi){
        if(!root) return 0;
        int leftH = f(root->left, maxi);
        int rghtH = f(root->right, maxi);

        maxi = max(maxi, leftH+rghtH);
        return 1 + max(leftH, rghtH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = -1;
        f(root, maxi);
        return maxi;
    }
};

int main() {

    return 0;
}