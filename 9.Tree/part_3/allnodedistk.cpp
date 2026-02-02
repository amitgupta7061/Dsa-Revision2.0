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
    void mapparentToeachNode(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(root->left){
            parent[root->left] = root;
            mapparentToeachNode(root->left, parent);
        }
        if(root->right){
            parent[root->right] = root;
            mapparentToeachNode(root->right, parent);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> visited;
        vector<int> result;

        mapparentToeachNode(root, parent);

        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        visited.insert(target);

        while (!q.empty()) {
            auto [node, dist] = q.front(); q.pop();

            if (dist == k) {
                result.push_back(node->val);
            }

            if (node->left && !visited.count(node->left)) {
                q.push({node->left, dist + 1});
                visited.insert(node->left);
            }
            if (node->right && !visited.count(node->right)) {
                q.push({node->right, dist + 1});
                visited.insert(node->right);
            }
            if (parent.count(node) && !visited.count(parent[node])) {
                q.push({parent[node], dist + 1});
                visited.insert(parent[node]);
            }
        }

        return result;
    }
};

int main() {

    return 0;
}