#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int v, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(v);
        for(auto it :  edges){
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;
        pq.push({0, 0});
        vector<int> visited(v, false);
        int sum = 0;
        
        while(!pq.empty()){
            auto [curr, node] = pq.top(); pq.pop();
            if(visited[node]) continue;
            visited[node] = true;
            sum += curr;

            for(auto [neigh, wt] : graph[node]){
                if(!visited[neigh]) pq.push({wt, neigh});
            }
        }
        return sum;
    }
};

int main() {

    return 0;
}