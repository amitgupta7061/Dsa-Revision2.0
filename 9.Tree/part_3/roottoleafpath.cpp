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
    void f(TreeNode* root, string curr, vector<string> &result){
        if(!root) return;
        if(!root->left and !root->right){
            curr += to_string(root->val);
            result.push_back(curr);
            return;
        }
        f(root->left, curr + to_string(root->val) + "->", result);
        f(root->right, curr + to_string(root->val) + "->", result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        f(root, "", result);
        return result;
    }
};

int main() {

    return 0;
}