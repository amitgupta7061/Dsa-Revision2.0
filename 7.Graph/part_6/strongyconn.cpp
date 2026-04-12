#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<vector<int>> &graph, int src, vector<int> &visited, stack<int> &st, bool stackopr){
        visited[src] = true;
        for(int neigh : graph[src]){
            if(!visited[neigh])
                f(graph, neigh, visited, st, stackopr);
        }
        if(stackopr) 
            st.push(src);
    }
    int kosaraju(int V, vector<vector<int>> &connections) {
        vector<int> visited(V, 0);
        vector<vector<int>> graph(V);

        for(auto conn : connections){
            graph[conn[0]].push_back(conn[1]);
        }
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!visited[i]) 
                f(graph, i, visited, st, true);
        }

        vector<vector<int>> transposeGraph(V);
        for(int i = 0; i < V; i++){
            visited[i] = 0;
            for(int neigh : graph[i])
                transposeGraph[neigh].push_back(i);
        }

        int strongCompp = 0;

        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(!visited[node]){
                strongCompp++;
                f(transposeGraph, node, visited, st, false);
            }
        }
        return strongCompp;
    }
};

int main() {

    return 0;
}