#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(vector<vector<int>> &adj, int node, vector<int> &samerec, vector<int> &visited){
        visited[node] = true;
        samerec[node] = true;
        for(int neigh : adj[node]){
            if(!visited[neigh]){
                if(f(adj, neigh, samerec, visited)) return true;
            }
            else if(samerec[neigh]) return true;
        }
        samerec[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> visited(V, false), samerec(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(f(adj, i, samerec, visited)) return true;
            }
        }
        return false;
    }
};

int main() {

    return 0;
}