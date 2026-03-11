#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:
    int findCeil(Node* root, int x) {
        Node* curr = root;
        int ans = -1;
        while(curr){
            if(curr->data >= x){
                ans = curr->data;
                curr = curr->left;
            }
            else curr = curr->right;
        }
        return ans;
    }
};


int main() {

    return 0;
}