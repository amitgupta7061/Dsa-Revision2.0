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
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, long long>> dq;
        dq.push_back({root, 0});

        long long result = 0;
        while(!dq.empty()){
            long long l = dq.front().second;
            long long r = dq.back().second;
            result = max(result, r - l + 1);

            for(int i = dq.size(); i > 0; i--){ 
                auto [node, ind] = dq.front(); dq.pop_front();
                ind -= l;

                if(node->left) dq.push_back({node->left, 2*ind+1});
                if(node->right) dq.push_back({node->right, 2*ind+2});
            }
        }
        return result;
    }
};

int main() {

    return 0;
}