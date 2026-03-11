#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void leftView(Node* root, vector<int> &result){
        if(!root) return;
        if(!root->left and !root->right) return;
        result.push_back(root->data);
        if(root->left) leftView(root->left, result);
        else leftView(root->right, result);
    }
    void bottomView(Node* root, vector<int> &result){
        if(not root) return;
        if(!root->left and !root->right) result.push_back(root->data);
        bottomView(root->left, result);
        bottomView(root->right, result);
    }
    void rightView(Node* root, vector<int> &result){
        if(not root) return;
        if(!root->left and !root->right) return;
        if(root->right) rightView(root->right, result);
        else rightView(root->left, result);
        result.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        if(!root->left and !root->right) return {root->data};
        vector<int> result; 
        result.push_back(root->data);
        leftView(root->left, result);
        bottomView(root, result);
        rightView(root->right, result);
        return result;
    }
};

int main() {

    return 0;
}