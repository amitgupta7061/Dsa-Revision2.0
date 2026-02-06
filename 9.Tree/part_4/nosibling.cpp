#include <bits/stdc++.h>
using namespace std;


struct Node
 {
     int data;
     Node* left, *right;
}; 

vector<int> noSibling(Node* node) {

}


class Solution {
public:
    vector<int> noSibling(Node* node) {
        vector<int> res;
        
        if(!node) return {-1};
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            if(curr->left && !curr->right)
                res.push_back(curr->left->data);
                
            if(curr->right && !curr->left)
                res.push_back(curr->right->data);
                
            if(curr->left)
                q.push(curr->left);
                
            if(curr->right)
                q.push(curr->right);
        }
        
        if(res.empty())
            return {-1};
            
        sort(res.begin(), res.end());
        
        return res;
    }
};


int main() {

    return 0;
}