#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(vector<vector<int>> &graph, int src, int col, vector<int> &color){
        color[src] = col;
        for(auto neigh : graph[src]){
            if(color[neigh] == -1){
                if(!DFS(graph, neigh, !col, color)) return false;
            } else if (color[neigh] == col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                if(!DFS(graph, i, 0, color)) return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}