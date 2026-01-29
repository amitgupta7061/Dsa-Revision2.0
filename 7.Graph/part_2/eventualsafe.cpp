#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reversegraph(n);
        vector<int> outdegree(n, 0);

        for(int u = 0; u < n; u++){
            outdegree[u] = graph[u].size();
            for(int v : graph[u]){
                reversegraph[v].push_back(u);
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(outdegree[i] == 0) q.push(i);
        }
        vector<bool> safe(n, false);
        while(q.size()){
            int node = q.front(); q.pop();
            safe[node] = true;
            for(int neigh : reversegraph[node]){
                if(--outdegree[neigh] == 0) q.push(neigh);
            }
        }

        vector<int> result;
        for(int i = 0; i < n; i++){
            if(safe[i]) result.push_back(i);
        }
        return result;
    }
};

int main() {

    return 0;
}