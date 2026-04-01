#include <bits/stdc++.h>
using namespace std;


struct Node {
    struct Node* left, *right;
    int data;
};


class Solution {
public:
    Node* LCA(Node* root, int p, int q){
        if(!root) return NULL;
        if(root->data == p || root->data == q) return root;
        Node* left = LCA(root->left, p, q);
        Node* right = LCA(root->right, p, q);
        if(left && right) return root;
        return left ? left : right;
    }
    int cntTurns(Node* root, int target, int dir){
        if(!root) return -1;
        if(root->data == target) return 0;
        int left = cntTurns(root->left, target, 0);
        int right = cntTurns(root->right, target, 1);
        if(left != -1) return dir == 1 ? left + 1 : left;
        if(right != -1) return dir == 0 ? right + 1 : right;
        return -1;
    }
    int NumberOFTurns(struct Node* root, int first, int second) {
        Node* lca = LCA(root, first, second);
        if(lca->data == first || lca->data == second) return -1;
        int d1 = cntTurns(lca, first, 0);
        int d2 = cntTurns(lca, second, 0);
        return d1 + d2;
    }
};

int main() {

    return 0;
}