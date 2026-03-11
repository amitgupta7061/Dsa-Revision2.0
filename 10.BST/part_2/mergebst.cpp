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
    bool isBSTsmaller(TreeNode* root, int& key){
        if(root->left && root->left->val >= key) return false;
        if(root->right && root->right->val >= key) return false;
        return true;
    }


    bool isBSTgreater(TreeNode* root, int& key){
        if(root->left && root->left->val <= key) return false;
        if(root->right && root->right->val <= key) return false;
        return true;
    }


    bool isValidBST(TreeNode* root, long& prev){  
        if(!root) return true;
        if(!isValidBST(root->left, prev)) return false;
        if(prev >= root->val) return false;
        prev = root->val;

        return isValidBST(root->right, prev);
    }


    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> mp;

        for(auto& root : trees)
            mp[root->val] = root;

        for(auto& root : trees){
            TreeNode *left = root->left;
            TreeNode *right = root->right;

            if(left && mp.count(left->val)){
                if(!isBSTsmaller(mp[left->val], root->val)) return nullptr;
                root->left = mp[left->val];
                mp.erase(left->val);
            }

            if(right && mp.count(right->val)){
                if(!isBSTgreater(mp[right->val], root->val)) return nullptr;
                root->right = mp[right->val];
                mp.erase(right->val);
            }
        }

        if(mp.size() == 1){
            TreeNode* root = mp.begin()->second;
            long prev = LONG_MIN;
            if(isValidBST(root, prev)) return root;
        }

        return nullptr;
    }
};

int main(){

    return 0;
}
