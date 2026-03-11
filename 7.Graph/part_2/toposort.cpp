#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        vector<int> result, indegree(V, 0);

        for(auto &it : edges){
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(q.size()){
            int node = q.front(); q.pop();
            result.push_back(node);
            for(int neigh : graph[node]){
                if(--indegree[neigh] == 0) q.push(neigh);
            }
        }
        if (result.size() != V) return {};
        return result;
    }
};

int main() {

    return 0;
}