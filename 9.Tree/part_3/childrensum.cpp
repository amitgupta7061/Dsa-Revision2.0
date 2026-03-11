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
    int isSumProperty(Node *root) {
        if(!root) return true;
        if(!root->left and !root->right) return true;
        int sum = 0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;

        if(sum != root->data) return false;
        return isSumProperty(root->left) and isSumProperty(root->right);
    }
};

int main() {

    return 0;
}