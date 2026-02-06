#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* nextRight;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        nextRight = nullptr;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);


        while(q.size()){
            Node* prev = NULL;
            for(int i = q.size(); i > 0; i--){
                Node* node = q.front(); q.pop();
                if(prev) prev->nextRight = node;
                prev = node;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            prev->nextRight = NULL;
        }
        return root;
    }
};

int main() {

    return 0;
}