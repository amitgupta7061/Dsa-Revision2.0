#include <bits/stdc++.h>
using namespace std;

class Solution{	
    class Node{
    public:
        vector<Node*> children;
        Node(){
            children.resize(26, NULL);
        }
    };
public:
    Node* root = new Node();
    int countDistinctSubstring(string s){
        int n = s.length();
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            Node* curr = root;
            for(int j = i; j < n; j++){
                int ind = s[j] - 'a';
                if(!curr->children[ind]){
                    cnt++;
                    curr->children[ind] = new Node();
                }
                curr = curr->children[ind];
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}