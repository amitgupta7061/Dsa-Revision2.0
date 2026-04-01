#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    void f(Node* root, int lev, int &maxi, int &mini){
        if(!root) return;
        mini = min(mini, lev);
        maxi = max(maxi, lev);
        f(root->left, lev-1, maxi, mini);
        f(root->right, lev+1, maxi, mini);
    }
    int verticalWidth(Node* root) {
        if(!root) return 0;
        int mini = 0;
        int maxi = 0;

        f(root, 0, maxi, mini);

        return maxi + abs(mini) + 1;
    }
};

int main() {

    return 0;
}