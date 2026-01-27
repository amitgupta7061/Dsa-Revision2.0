#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w * 2});
        }
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (pq.size()) {
            auto [currweight, node] = pq.top(); pq.pop();
            if (currweight > dist[node]) continue;
            if (node == n - 1) return currweight;

            for (auto& [neigh, edgeweight] : adj[node]) {
                int newweight = currweight + edgeweight;
                if (newweight < dist[neigh]) {
                    dist[neigh] = newweight;
                    pq.push({newweight, neigh});
                }
            }
        }
        return -1;
    }
};


int main() {

    return 0;
}