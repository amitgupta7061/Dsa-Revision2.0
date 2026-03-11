#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), INF = 1e9;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        function<int(int, int, int)> f = [&](int i, int j, int used) -> int {
            if (i == m - 1 && j == n - 1) return 0;
            if (dp[i][j][used] != -1) return dp[i][j][used];

            int ans = INF;

            if (j + 1 < n) ans = min(ans, grid[i][j + 1] + f(i, j + 1, used)); //right
            if (i + 1 < m) ans = min(ans, grid[i + 1][j] + f(i + 1, j, used)); //down
            
            if (used < k) {
                for (int x = 0; x < m; x++) {
                    for (int y = 0; y < n; y++) {
                        if (grid[x][y] <= grid[i][j]) {
                            ans = min(ans, f(x, y, used + 1));
                        }
                    }
                }
            }

            return dp[i][j][used] = ans;
        };

        return f(0, 0, 0);
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), INF = 1e9 + 7, maxi = 10001;
        vector<vector<int>> dp(m, vector<int>(n, INF));

        dp[0][0] = 0;
        auto f = [&](vector<vector<int>>& curr) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (curr[i][j] == INF) continue;
                    if (i + 1 < m) curr[i + 1][j] = min(curr[i + 1][j], curr[i][j] + grid[i + 1][j]);
                    if (j + 1 < n) curr[i][j + 1] = min(curr[i][j + 1], curr[i][j] + grid[i][j + 1]);
                }
            }
        };

        f(dp);
        for (int t = 0; t < k; ++t) {
            vector<vector<int>> nextdp = dp;
            vector<int> mini(maxi + 1, INF);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i][j] != INF) {
                        int val = grid[i][j];
                        mini[val] = min(mini[val], dp[i][j]);
                    }
                }
            }

            vector<int> suffixmin(maxi + 1, INF);
            int currSuffixmin = INF;
            for (int v = maxi; v >= 0; --v) {
                currSuffixmin = min(currSuffixmin, mini[v]);
                suffixmin[v] = currSuffixmin;
            }

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int val = grid[i][j];
                    if (suffixmin[val] != INF) {
                        nextdp[i][j] = min(nextdp[i][j], suffixmin[val]);
                    }
                }
            }

            f(nextdp);
            dp = nextdp;
        }

        return dp[m - 1][n - 1];
    }
};

int main() {

    return 0;
}