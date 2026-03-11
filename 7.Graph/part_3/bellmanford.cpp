#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int v, vector<vector<int>>& edges, int src) {
        vector<int> dist(v, 1e8);
        dist[src] = 0;

        for(int i = 0; i < v-1; i++){
            for(auto it : edges){
                int u = it[0], v = it[1], w = it[2];
                if(dist[u] != 1e8 and dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                }
            }
        }

        for(int i = 0; i < v-1; i++){
            for(auto it : edges){
                int u = it[0], v = it[1], w = it[2];
                if(dist[u] != 1e8 and dist[v] > dist[u] + w) return {-1};
            }
        }
        return dist;
    }
};


int main() {

    return 0;
}