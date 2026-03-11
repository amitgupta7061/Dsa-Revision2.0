#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> result(m, vector<int>(n, -1));
        vector<int> directions = {0, 1, 0, -1, 0};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    result[i][j] = 0;
                }
            }
        }

        while(q.size()){
            auto [r, c] = q.front(); q.pop();
            for(int d = 0; d < 4; d++){
                int nr = r + directions[d], nc = c + directions[d+1];
                if(nr < 0 or nc < 0 or nr >= m or nc >= n or result[nr][nc] != -1) continue;
                result[nr][nc] = result[r][c] + 1;
                q.push({nr, nc});
            }
        }

        return result;
    }
};

int main() {

    return 0;
}