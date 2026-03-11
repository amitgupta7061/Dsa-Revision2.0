#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto it : flights){
            graph[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, 1e9);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0}); // step, node, cost

        while(!pq.empty()){
            auto [step, node, cost] = pq.top(); pq.pop();

            for(auto [neigh, wt] : graph[node]){
                if(dist[neigh] > cost + wt and step <= k){
                    dist[neigh] = cost + wt;
                    pq.push({step+1, neigh, dist[neigh]});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

int main() {

    return 0;
}