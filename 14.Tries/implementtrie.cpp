#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    vector<Node*> children;
    bool isTerminal;
    Node(){
        children.resize(26, 0);
        isTerminal = false;
    }
};

class Trie {
public:
    Node* root = new Node();
    Trie() {
        
    }

    void insert(string &word) {
        Node* curr = root;
        for(char ch : word){
            int ind = ch - 'a';
            if(curr->children[ind])
                curr = curr->children[ind];
            else {
                curr->children[ind] = new Node();
                curr = curr->children[ind];
            }
        }
        curr->isTerminal = true;
    }

    bool search(string &word) {
        Node* curr = root;
        for(char ch : word){
            int ind = ch - 'a';
            if(curr->children[ind])
                curr = curr->children[ind];
            else
                return false;
        }
        return curr->isTerminal;
    }

    bool isPrefix(string &word) {
        Node* curr = root;
        for(char ch : word){
            int ind = ch - 'a';
            if(curr->children[ind])
                curr = curr->children[ind];
            else
                return false;
        }
        return true;
    }
};


int main() {

    return 0;
}