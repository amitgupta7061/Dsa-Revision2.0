#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string result = "";

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(!node) result += "#,";
            else result += to_string(node->val) + ',';

            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return result;
    }
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();

            getline(ss, val, ',');
            if(val == "#") node->left = NULL;
            else {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            getline(ss, val, ',');
            if(val == "#") node->right = NULL;
            else {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};

int main() {

    return 0;
}