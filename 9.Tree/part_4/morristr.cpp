#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    vector<int> preorder(TreeNode* root){
        vector<int> result;
        TreeNode* curr = root;

        while(curr){
            if(curr->left == NULL){
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while(pred->right and pred->right != curr)  pred = pred->right;

                if(pred->right == NULL){
                    result.push_back(curr->val);
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    curr = curr->right;
                }   
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while(curr){
            if(curr->left == NULL){
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right and pred->right != curr) pred = pred->right;

                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};

int main() {

    return 0;
}