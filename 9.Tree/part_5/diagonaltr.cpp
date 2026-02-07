#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    vector<int> diagonal(Node *root) {
        vector<int> result;
        queue<Node*> q;
        q.push(root);

        while(q.size()){
            Node* curr = q.front(); q.pop();

            while(curr){
                if(curr->left) q.push(curr->left);
                result.push_back(curr->data);
                curr = curr->right;
            }
        }
        return result;
    }
};

int main() {

    return 0;
}