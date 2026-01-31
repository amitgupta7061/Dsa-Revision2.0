#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<tuple<int, int, TreeNode*>> q;
        q.push({0, 0, root});  // col, row, node

        while(!q.empty()){
            auto [c, r, node] = q.front(); q.pop();
            mp[c][r].insert(node->val);

            if(node->left) q.push({c-1, r+1, node->left});
            if(node->right) q.push({c+1, r+1, node->right});
        }

        vector<vector<int>> result;
        for(auto &col : mp){
            vector<int> currlevel;
            for(auto &[_, data] : col.second){
                currlevel.insert(currlevel.end(), data.begin(), data.end());
            }
            result.push_back(currlevel);
        }
        return result;

    }
};

int main() {

    return 0;
}