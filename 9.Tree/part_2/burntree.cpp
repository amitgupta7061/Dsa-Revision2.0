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

class Solution {
public:
    unordered_map<Node*, Node*> parent;
    unordered_set<Node*> isburn;
    void searching(Node* root,int k,Node*& first){
        if(root==NULL) return;
        if(root->data==k){
            first = root;
            return;
        }
        searching(root->left,k,first);
        searching(root->right,k,first);
    }
    void parent_mappingg(Node* root){
        if(root == nullptr) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        parent_mappingg(root->left);
        parent_mappingg(root->right);
    }
    int minTime(Node* root, int target) {
        queue<pair<Node*, int>> q;
        parent_mappingg(root);
        Node* first = NULL;
        searching(root, target, first);
        int level = 0;
        q.push({first, level});
        isburn.insert(first);
        while(q.size() > 0){
            Node* temp = q.front().first;
            level = q.front().second;
            q.pop();
            if(temp->left){
                if(isburn.find(temp->left) == isburn.end()){
                    q.push({temp->left, level+1});
                    isburn.insert(temp->left);
                }
            } if(temp->right){
                if(isburn.find(temp->right) == isburn.end()){
                    q.push({temp->right, level+1});
                    isburn.insert(temp->right);
                }
            } if(parent.find(temp) != parent.end()){
                if(isburn.find(parent[temp]) == isburn.end()){
                    q.push({parent[temp], level+1});
                    isburn.insert(parent[temp]);
                }
            }
        }
        return level;
    }
};

int main() {

    return 0;
}