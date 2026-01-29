#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> graph(n);
        for(auto it : roads){
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> dist(n, 1e15), cnt(n, 0);
        priority_queue<tuple<long long, long long>, vector<tuple<long long, long long>>, greater<>> pq;
        pq.push({0, 0}); 
        dist[0] = 0;
        cnt[0] = 1;
        const int MOD = 1e9 + 7;

        while(!pq.empty()){
            auto [cost, node] = pq.top(); pq.pop();

            for(auto [neigh, wt] : graph[node]){
                if(dist[neigh] > cost + wt){
                    dist[neigh] = cost + wt;
                    cnt[neigh] = cnt[node];
                    pq.push({dist[neigh], neigh});
                } else if(dist[neigh] == cost+wt){
                    cnt[neigh] =  (cnt[neigh] + cnt[node]) % MOD;
                }
            }
        }
        return cnt[n-1];
    }
};

int main() {

    return 0;
}