#include <bits/stdc++.h>
using namespace std;

int maxChocPick(vector<vector<int>>& grid, int r, int c1, int c2, int n, int m, vector<vector<vector<int>>>& dp) {
    if (c1 < 0 or c1 >= m or c2 < 0 or c2 >= m) return -1e9;

    if (r == n - 1) {
        if (c1 == c2) return grid[r][c1];
        return grid[r][c1] + grid[r][c2];
    }
    if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

    int result = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int cost;
            if (c1 == c2) cost = grid[r][c1];
            else cost = grid[r][c1] + grid[r][c2];
            cost += maxChocPick(grid, r + 1, c1 + i, c2 + j, n, m, dp);
            result = max(result, cost);
        }
    }

    return dp[r][c1][c2] = result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    cout << maxChocPick(grid, 0, 0, m - 1, n, m, dp);

    return 0;
}