#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(vector<vector<int>> &adj, int node, int parent, vector<int> &visited){
        visited[node] = true;
        for(int neigh : adj[node]){
            if(!visited[neigh]){
                if(f(adj, neigh, node, visited)) return true;
            }
            else if(neigh != parent) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(f(adj, i, -1, visited)) return true;
            }
        }
        return false;
    }
};

int main() {

    return 0;
}