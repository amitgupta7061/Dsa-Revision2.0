#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        vector<vector<int>> graph(26);
        vector<int> indegree(26, 0);
        vector<int> present(26, 0);

        for(auto &w : words){
            for(char c : w) present[c - 'a'] = 1;
        }

        for(int i = 0; i < n - 1; i++){
            int len = min(words[i].length(), words[i+1].length());
            bool found = false;

            for(int j = 0; j < len; j++){
                if(words[i][j] != words[i+1][j]){
                    graph[words[i][j] - 'a'].push_back(words[i+1][j] - 'a');
                    indegree[words[i+1][j] - 'a']++;
                    found = true;
                    break;
                }
            }

            if(!found && words[i].length() > words[i+1].length()) return "";
        }

        queue<int> q;
        for(int i = 0; i < 26; i++){
            if(present[i] and indegree[i] == 0) q.push(i);
        }

        string result;
        while(q.size()){
            int node = q.front(); q.pop();
            result += char('a' + node);

            for(int neigh : graph[node]){
                if(--indegree[neigh] == 0) q.push(neigh);
            }
        }
        if(count(present.begin(), present.end(), 1) != result.size()) return "";

        return result;
    }
};


int main() {

    return 0;
}