#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<int> serialize(Node *root) {
        vector<int> result;
        queue<Node*> q;
        q.push(root);

        while(q.size()){
            Node* curr = q.front(); q.pop();
            if(curr){
                result.push_back(curr->data);
                q.push(curr->left);
                q.push(curr->right);
            }
            else {
                result.push_back(-1);
            }
        }
        return result;
    }

    Node *deSerialize(vector<int> &arr) {
        Node* root = new Node(arr[0]);
        int ind = 1;
        queue<Node*> q;
        q.push(root);

        while(q.size()){
            Node* curr = q.front(); q.pop();

            if(arr[ind] == -1){
                curr->left = NULL; ind++;
            } else{
                curr->left = new Node(arr[ind]); ind++;
                q.push(curr->left);
            }
            if(ind >= arr.size()) break;
            if(arr[ind] == -1){
                curr->right = NULL; ind++;
            } else{
                curr->right = new Node(arr[ind]); ind++;
                q.push(curr->right);
            }
        }
        return root;
    }   
};

int main() {

    return 0;
}