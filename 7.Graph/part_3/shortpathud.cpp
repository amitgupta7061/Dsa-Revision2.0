#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> graph(V);
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while(pq.size()){
            auto [step, node] = pq.top(); pq.pop();
            if(step > dist[node]) continue;

            for(int &neigh : graph[node]){
                if(dist[neigh] > step+1){
                    dist[neigh] = step + 1;
                    pq.push({step+1, neigh});
                }
            }
        }
        for(int i = 0; i < V; i++) if(dist[i] == INT_MAX) dist[i] = -1;
        return dist;
    }
};

class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> graph(V);
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        vector<int> dist(V, INT_MAX);
        queue<pair<int, int>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while(pq.size()){
            auto [step, node] = pq.front(); pq.pop();
            if(step > dist[node]) continue;

            for(int &neigh : graph[node]){
                if(dist[neigh] > step+1){
                    dist[neigh] = step + 1;
                    pq.push({step+1, neigh});
                }
            }
        }
        for(int i = 0; i < V; i++) if(dist[i] == INT_MAX) dist[i] = -1;
        return dist;
    }
};

int main() {

    return 0;
}