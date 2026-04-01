#include <bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void f(Node* root, int len, int sum, int &maxLen, int &maxSum) {
        if (!root) return;

        sum += root->data;

        // leaf node
        if (!root->left && !root->right) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {
                maxSum = max(maxSum, sum);
            }
            return;
        }

        f(root->left, len + 1, sum, maxLen, maxSum);
        f(root->right, len + 1, sum, maxLen, maxSum);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int maxLen = -1;
        int maxSum = 0;
        f(root, 0, 0, maxLen, maxSum);
        return maxSum;
    }
};

int main() {

    return 0;
}