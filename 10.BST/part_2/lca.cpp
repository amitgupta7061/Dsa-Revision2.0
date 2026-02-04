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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while(curr){
            if(curr->val > p->val and curr->val > q->val) curr = curr->left;
            else if(curr->val < p->val and curr->val < q->val) curr = curr->right;
            else return curr; 
        }
        return NULL;
    }
};

int main() {

    return 0;
}