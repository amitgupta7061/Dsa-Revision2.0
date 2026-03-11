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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key){
            if(root->left == NULL and root->right == NULL) return NULL;
            else if(root->left == NULL) return root->right;
            else if(root->right == NULL) return root->left;
            else {
                TreeNode* pred = root->left;
                while(pred->right) pred = pred->right;
                swap(root->val, pred->val);
                root->left = deleteNode(root->left, key);
            }
        } 
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else root->right = deleteNode(root->right, key);
        return root;
    }
};

int main() {

    return 0;
}