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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* curr = root;

        while(curr){
            if(curr->val > val){
                if(curr->left == NULL){
                    curr->left = new TreeNode(val);
                    return root;
                } else curr = curr->left;
            } else {
                if(curr->right == NULL){
                    curr->right = new TreeNode(val);
                    return root;
                } else curr = curr->right;
            }
        }
        return root;
    }
};

int main() {

    return 0;
}