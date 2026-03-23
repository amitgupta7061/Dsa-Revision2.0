#include <bits/stdc++.h>
using namespace std;

class Solution {
    class Node{
    public:
        vector<Node*> child;
        Node(){
            child.resize(2, NULL);
        }
    };
public:
    Node* root = new Node();
    void insert(int num){
        Node* curr = root;

        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(!curr->child[bit])
                curr->child[bit] = new Node();
            curr = curr->child[bit];
        }   
    }
    int getmaxi(int num){
        Node* curr = root;
        int maxi = 0;

        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            int opp = !bit;

            if(curr->child[opp]){
                maxi |= (1 << i);
                curr = curr->child[opp];
            } else  
                curr = curr->child[bit];
        }

        return maxi;
    }
    int findMaximumXOR(vector<int>& nums) {
        for(int num : nums)
            insert(num);

        int result = 0;
        for(int num : nums)
            result = max(result, getmaxi(num));
        return result;
    }
};

int main() {

    return 0;
}