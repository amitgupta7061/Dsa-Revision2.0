#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void DFS(int node, vector<vector<int>> &graph, vector<int> &visited, stack<int> &st, bool stackopr){
        visited[node] = true;
        for(int &neigh : graph[node]){
            if(!visited[neigh]) DFS(neigh, graph, visited, st, stackopr);
        }
        if(stackopr) st.push(node);
    }
    int kosaraju(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> visited(n, false);
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(!visited[i]) DFS(i, graph, visited, st, true);
        }

        vector<vector<int>> transpose(n);
        for(int i = 0; i < n; i++){
            for(int &neigh : graph[i]){
                transpose[neigh].push_back(i);
            }
        }

        fill(visited.begin(), visited.end(), false);
        int strongcomp = 0;
        while(st.size()){
            int node = st.top(); st.pop();
            if(!visited[node]){
                strongcomp++;
                DFS(node, transpose, visited, st, false);
            }
        }
        return strongcomp;
    }
};

int main() {

    return 0;
}