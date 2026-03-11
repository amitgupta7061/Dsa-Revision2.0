#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int v, int e, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(v);
        for(auto it : edges){
            graph[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(v, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[0] = 0;
        pq.push({0, 0});

        while(pq.size()){
            auto [step, node] = pq.top(); pq.pop();
            if(step > dist[node]) continue;

            for(auto &[neigh, weight] : graph[node]){
                if(dist[neigh] > step+weight){
                    dist[neigh] = step + weight;
                    pq.push({step+weight, neigh});
                }
            }
        }
        for(int i = 0; i < v; i++) if(dist[i] == INT_MAX) dist[i] = -1;
        return dist;
    }
};

class Solution {
public:
    vector<int> shortestPath(int v, int e, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(v);
        vector<int> indegree(v, 0);

        for(auto &it : edges){
            graph[it[0]].push_back({it[1], it[2]});
            indegree[it[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < v; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while(q.size()){
            int node = q.front(); q.pop();
            topo.push_back(node);

            for(auto &it : graph[node]){
                int neigh = it.first;
                if(--indegree[neigh] == 0) q.push(neigh);
            }
        }

        vector<int> dist(v, INT_MAX);
        dist[0] = 0;

        for(int node : topo){
            if(dist[node] == INT_MAX) continue;

            for(auto &[neigh, wt] : graph[node]){
                if(dist[neigh] > dist[node] + wt){
                    dist[neigh] = dist[node] + wt;
                }
            }
        }

        for(int i = 0; i < v; i++)
            if(dist[i] == INT_MAX) dist[i] = -1;

        return dist;
    }
};


int main() {

    return 0;
}