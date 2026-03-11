#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    int f(Node* root, int &maxi){
        if(!root) return 0;
        if(!root->left && !root->right) return root->data;

        int l = f(root->left, maxi);
        int r = f(root->right, maxi);

        if(root->left && root->right){
            maxi = max(maxi, l + r + root->data);
            return root->data + max(l, r);
        }

        return root->left ? root->data + l : root->data + r;
    }

    int maxPathSum(Node* root) {
        int maxi = INT_MIN;
        int val = f(root, maxi);

        if(maxi == INT_MIN) return val;
        return maxi;
    }
};


int main() {

    return 0;
}