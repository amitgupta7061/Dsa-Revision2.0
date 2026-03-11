#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        visited[0][0] = true;

        vector<int> directions = {0, 1, 0, -1, 0};

        while(pq.size()){
            auto [time, r, c] = pq.top(); pq.pop();
            if(r == n-1 and c == n-1) return time;

            for(int d = 0; d < 4; d++){
                int nr = r + directions[d], nc = c + directions[d+1];
                if(nr >= 0 and nc >= 0 and nr < n and nc < n and !visited[nr][nc]){
                    int newTime = max(time, grid[nr][nc]);
                    visited[nr][nc] = true;
                    pq.emplace(newTime, nr, nc);
                }
            }
        }

        return -1;
    }
};

int main() {

    return 0;
}