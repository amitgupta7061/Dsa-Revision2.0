#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class NodeValue{
public:
    int minValue, maxValue, maxSize;
    NodeValue(int minValue, int maxValue, int maxSize){
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->maxSize = maxSize;
    }
};

class Solution {
public:
    NodeValue f(Node* root){
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0);
        NodeValue l = f(root->left);
        NodeValue r = f(root->right);
        if(root->data > l.maxValue and root->data < r.minValue){
            return NodeValue(min(root->data, l.minValue), max(root->data, r.maxValue), l.maxSize+r.maxSize+1);
        } else {
            return NodeValue(INT_MIN, INT_MAX, max(l.maxSize, r.maxSize));
        }
    }
    int largestBst(Node *root) {
        return f(root).maxSize;
    }
};

int main() {

    return 0;
}