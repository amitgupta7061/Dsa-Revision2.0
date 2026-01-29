#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto it : times){
            graph[it[0]-1].push_back({it[1]-1, it[2]});
        }
        vector<int> dist(n, 1e9);
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;
        pq.push({0, k-1}); 
        dist[k-1] = 0;

        while(!pq.empty()){
            auto [time, node] = pq.top(); pq.pop();

            for(auto [neigh, wt] : graph[node]){
                if(dist[neigh] > time + wt){
                    dist[neigh] = time + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        int maxi = -1;
        for(int it : dist){
            if(it == 1e9) return -1;
            maxi = max(maxi, it);
        }
        return maxi;
    }
};

int main() {

    return 0;
}