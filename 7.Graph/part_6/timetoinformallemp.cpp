#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<int>> &graph, int src, int curr, int& maxTime, vector<int> &informTime, vector<int> &visited){
        visited[src] = true;
        maxTime = max(maxTime, curr);

        for(int &neigh : graph[src])
            if(!visited[neigh])
                DFS(graph, neigh, curr+informTime[src], maxTime, informTime, visited);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++){
            if(i == headID) 
                continue;
            graph[i].push_back(manager[i]);
            graph[manager[i]].push_back(i);
        }

        int maxTime = 0;
        vector<int> visited(n, false);
        DFS(graph, headID, 0, maxTime, informTime, visited);
        return maxTime;
    }
};

int main() {

    return 0;
}