#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCostPath(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        pq.push({grid[0][0],{ 0, 0}});
        dist[0][0] = grid[0][0];

        vector<int> directions = {0, 1, 0, -1, 0};

        while(!pq.empty()){
            auto [curr,pos] = pq.top(); pq.pop();
            int r = pos.first, c = pos.second;
            if(curr > dist[r][c]) continue;
            if(r == n-1 and c == n-1) return curr;

            for(int d = 0; d < 4; d++){
                int nr = r + directions[d], nc = c + directions[d+1];
                if(nr >= 0 and nc >= 0 and nr < n and nc < n and dist[nr][nc] > grid[nr][nc] + curr){
                    dist[nr][nc] = grid[nr][nc] + curr;
                    pq.push({dist[nr][nc],{ nr, nc}});
                }
            }
        }
        return dist[n-1][n-1];
    }
};

int main() {

    return 0;
}