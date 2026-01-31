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
        int leftS = max(f(root->left, maxi), 0);
        int rghtS = max(f(root->right, maxi), 0);
        maxi = max(maxi, root->val+leftS+rghtS);

        return root->val + max(leftS, rghtS);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        f(root, maxi);
        return maxi;
    }
};

int main() {

    return 0;
}