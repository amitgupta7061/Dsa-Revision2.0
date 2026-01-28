#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> st;
        vector<int> directions = {0, 1, 0, -1, 0};

        function<void(int,int,int,int,vector<pair<int,int>>&, vector<vector<int>>&)> f = [&](int r, int c, int sr, int sc, vector<pair<int, int>> &shape, vector<vector<int>> &grid) -> void {
            grid[r][c] = 0;
            shape.push_back({r-sr, c-sc});

            for(int d = 0; d < 4; d++){
                int nr = r + directions[d], nc = c + directions[d+1];
                if(nr >= 0 and nc >= 0 and nr < m and nc < n and grid[nr][nc]){
                    f(nr, nc, sr, sc, shape, grid);
                }
            }
        };

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    vector<pair<int, int>> shape;
                    f(i, j, i, j, shape, grid);
                    st.insert(shape);
                }
            }
        }

        return st.size();
    }
};


int main() {

    return 0;
}