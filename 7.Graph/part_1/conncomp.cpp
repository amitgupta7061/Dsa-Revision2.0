#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<vector<int>> &adj, int node, vector<int> &currcomp, vector<bool> &visited, vector<vector<int>> &result){
        currcomp.push_back(node);
        visited[node] = true;
        for(int neigh : adj[node]){
            if(!visited[neigh]) f(adj, neigh, currcomp, visited, result);
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(V, false);
        vector<vector<int>> result;
        for(int i = 0; i < V; i++){
            vector<int> currcomp;
            if(!visited[i]) f(adj, i, currcomp, visited, result);
            if(currcomp.size()) result.push_back(currcomp);
        }
        return result;
    }
};


int main() {

    return 0;
}