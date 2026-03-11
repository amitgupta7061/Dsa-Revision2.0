#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
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
    Node* nextInorder(Node* &root){
        while(root){
            if(root->left == NULL){
                Node* temp = root;
                root = root->right;
                return temp;
            } else{
                Node* pred = root->left;
                while(pred->right and pred->right != root) pred = pred->right;

                if(pred->right == NULL){
                    pred->right = root;
                    root = root->left;
                } else {
                    pred->right = NULL;
                    Node* temp = root;
                    root = root->right;
                    return temp;
                }
            }
        }
        NULL;
    }
    vector<int> merge(Node *root1, Node *root2) {
        Node *node1 = root1, *node2 = root2;
        Node *next1 = nextInorder(node1);
        Node *next2 = nextInorder(node2);

        vector<int> result;
        while(next1 and next2){
            if(next1->data <= next2->data){
                result.push_back(next1->data);
                next1 = nextInorder(node1);
            } else {
                result.push_back(next2->data);
                next2 = nextInorder(node2);
            }
        }

        while(next1){
            result.push_back(next1->data);
            next1 = nextInorder(node1);
        }
        while(next2){
            result.push_back(next2->data);
            next2 = nextInorder(node2);
        }
        return result;
    }
};

int main() {

    return 0;
}