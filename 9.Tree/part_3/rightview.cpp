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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while(q.size()){
            TreeNode* node = q.front().first; int lev = q.front().second; q.pop();
            if(result.size() == lev) result[result.size() - 1] = node->val;
            else result.push_back(node->val);

            if(node->left) q.push({node->left, lev+1});
            if(node->right) q.push({node->right, lev+1});
        }
        return result;
    }
};

int main() {

    return 0;
}