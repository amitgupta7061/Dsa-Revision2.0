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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool even = true;

        while(!q.empty()) {
            int size = q.size();
            int prev = even ? INT_MIN : INT_MAX;

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(even) {
                    if(node->val % 2 == 0 || node->val <= prev) return false;
                } else {
                    if(node->val % 2 == 1 || node->val >= prev) return false;
                }
                prev = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            even = !even;
        }

        return true;
    }
};

int main() {

    return 0;
}