#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* f(vector<int> &in, vector<int> &post, int &ind, int l, int r){
        if(l > r) return NULL;
        TreeNode* root = new TreeNode(post[ind]);
        int i;
        for(i = l; i <= r; i++) if(post[ind] == in[i]) break;
        ind--;
        root->right = f(in, post, ind, i+1, r);
        root->left = f(in, post, ind, l, i-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ind = postorder.size() - 1;
        return f(inorder, postorder, ind, 0, ind);
    }
};

int main() {

    return 0;
}