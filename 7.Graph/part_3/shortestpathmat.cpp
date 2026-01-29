#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({1, 0, 0});

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        while(!pq.empty()){
            auto [dist, r, c] = pq.top(); pq.pop();
            if(r == n-1 and c == n-1) return dist;

            for(auto [dx, dy] : directions){
                int nr = r + dx, nc = c + dy;
                if(nr >= 0 and nc >= 0 and nr < n and nc < n and grid[nr][nc] == 0){
                    pq.push({dist+1, nr, nc});
                }
            }
        }
        return -1;
    }
};

int main() {

    return 0;
}