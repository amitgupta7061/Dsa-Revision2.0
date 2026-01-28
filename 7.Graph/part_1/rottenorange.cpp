#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cntoffresh = 0, cntofrotten = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) cntoffresh++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }
        if(cntoffresh == 0) return 0;
        int result = 0;
        vector<int> direction = {0, 1, 0, -1, 0};

        while(q.size()){
            bool foundrotted = false;
            for(int i = q.size(); i > 0; i--){
                auto [r, c] = q.front(); q.pop();
                for(int d = 0; d < 4; d++){
                    int nr = r + direction[d], nc = c + direction[d+1];
                    if(nr < 0 or nc < 0 or nr >= m or nc >= n or grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;
                    foundrotted = true;
                    cntoffresh--;
                    q.push({nr, nc});
                }
            }
            if(foundrotted) result++;
        }
        return cntoffresh == 0 ? result : -1;
    }
};

int main() {

    return 0;
}