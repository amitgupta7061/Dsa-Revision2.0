#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), result = 0;
        queue<pair<int, int>> q;
        vector<int> directions = {0, 1, 0, -1, 0};

        for(int i = 0; i < n; i++){ // 1st row and last row
            if(grid[0][i] == 1) {
                q.push({0, i});
                grid[0][i] = 2;
            }
            if(grid[m-1][i] == 1) {
                q.push({m-1, i});
                grid[m-1][i] = 2;
            }
        }

        for(int i = 0; i < m; i++){ // 1st col and last col
            if(grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 2;
            }
            if(grid[i][n-1] == 1) {
                q.push({i, n-1});
                grid[i][n-1] = 2;
            }
        }

        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();
            for(int d = 0; d < 4; d++){
                int nrow = row + directions[d], ncol = col + directions[d+1];
                if(nrow < 0 or ncol < 0 or nrow >= m or ncol >= n or grid[nrow][ncol] != 1)
                    continue;
                grid[nrow][ncol] = 2; 
                q.push({nrow, ncol});
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) result++;
            }
        }
        return result;
    }
};

int main() {

    return 0;
}