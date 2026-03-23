#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    class Node
    {
    public:
        vector<Node *> children;
        bool isTerminal;
        int count = 0;
        Node()
        {
            children.resize(26, 0);
            isTerminal = false;
        }
    };
    Node *root = new Node();
    Trie() {}
    void insert(string &word)
    {
        Node *curr = root;
        for (char ch : word)
        {
            int ind = ch - 'a';
            if (!curr->children[ind])
                curr->children[ind] = new Node();
            curr = curr->children[ind];
            curr->count++;
        }
        curr->isTerminal = true;
    }
    string getValidpref(string &word, int n)
    {
        string currpref = "";
        string result = "";
        Node *curr = root;
        for (char ch : word)
        {
            int ind = ch - 'a';
            if (curr->children[ind] and curr->children[ind]->count == n)
            {
                currpref += ch;
                if (curr->children[ind]->isTerminal)
                    result = currpref;
                curr = curr->children[ind];
            }
            else
                return result;
        }
        return result;
    }
};
class Solution
{
public:
    string longestcommonprefix(vector<string> &words)
    {
        Trie t;
        for (string &word : words)
            t.insert(word);
        return t.getValidpref(words[0], words.size());;
    }
};

int main()
{

    return 0;
}