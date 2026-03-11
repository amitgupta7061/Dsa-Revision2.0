#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> topView(Node *root) {
        unordered_map<int, int> mp; // level, val
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        int maxilevel = INT_MIN, minilevel = INT_MAX;

        while(!q.empty()){
            auto [node, lev] = q.front(); q.pop();
            minilevel = min(minilevel, lev);
            maxilevel = max(maxilevel, lev);
            if(!mp.count(lev)) mp[lev] = node->data;
            if(node->left) q.push({node->left, lev-1});
            if(node->right) q.push({node->right, lev+1});
        }

        vector<int> result;
        for(int i = minilevel; i <= maxilevel; i++){
            result.push_back(mp[i]);
        }
        return result;
    }
};

int main() {

    return 0;
}