#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    class Node {
    public:
        vector<Node*> children;
        bool isTerminal;

        Node() {
            children.resize(26, NULL);
            isTerminal = false;
        }
    };

    Node* root = new Node();

    void insert(string &word) {
        Node* curr = root;
        for(char ch : word) {
            int ind = ch - 'a';
            if(!curr->children[ind])
                curr->children[ind] = new Node();
            curr = curr->children[ind];
        }
        curr->isTerminal = true;
    }

    bool isValid(string &word) {
        Node* curr = root;
        for(char ch : word) {
            int ind = ch - 'a';
            curr = curr->children[ind];
            if(!curr || !curr->isTerminal)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie t;
        for(string &word : words)
            t.insert(word);

        string ans = "";

        for(string &word : words) {
            if(t.isValid(word)) {
                if(word.length() > ans.length() || 
                  (word.length() == ans.length() && word < ans)) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};


int main() {

    return 0;
}