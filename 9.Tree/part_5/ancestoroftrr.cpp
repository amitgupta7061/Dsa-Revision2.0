#include <bits/stdc++.h>
using namespace std;


struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};


class Solution {
public:
  
    bool solve(Node* root, int target, vector<int>& ans) {
        if (root == NULL) return false;
        
        if (root->data == target) return true;
        
        if (solve(root->left, target, ans) || solve(root->right, target, ans)) {
            ans.push_back(root->data);
            return true;
        }
        
        return false;
    }
  
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int> ans;
        solve(root, target, ans);
        return ans;
    }
};

int main() {

    return 0;
}