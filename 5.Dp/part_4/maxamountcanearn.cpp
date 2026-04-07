#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int dp[501][501][3];
    bool vis[501][501][3];

    int f(vector<vector<int>>& coins, int r, int c, int power){
        if(r >= m || c >= n) return -1e9;

        if(r == m-1 && c == n-1){
            if(coins[r][c] < 0 && power)
                return 0;
            else 
                return coins[r][c];
        }

        if(vis[r][c][power]) return dp[r][c][power];

        int usedpower = -1e9;

        if(coins[r][c] < 0 && power){
            usedpower = max(
                f(coins, r+1, c, power-1),
                f(coins, r, c+1, power-1)
            );
        }

        int notused = coins[r][c] + max(
            f(coins, r+1, c, power),
            f(coins, r, c+1, power)
        );

        vis[r][c][power] = true;
        return dp[r][c][power] = max(usedpower, notused);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        memset(vis, false, sizeof(vis));

        return f(coins, 0, 0, 2);
    }
};


class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        const int NEG = -1e9;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, NEG)));

        // Base case (0,0)
        for(int k = 0; k <= 2; k++){
            if(coins[0][0] < 0 && k > 0)
                dp[0][0][k] = 0;   // neutralize
            else
                dp[0][0][k] = coins[0][0];
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;

                for(int k = 0; k <= 2; k++){
                    int best = NEG;

                    // From top
                    if(i > 0){
                        // not using power
                        best = max(best, dp[i-1][j][k] + coins[i][j]);

                        // using power
                        if(coins[i][j] < 0 && k > 0){
                            best = max(best, dp[i-1][j][k-1]);
                        }
                    }

                    // From left
                    if(j > 0){
                        // not using power
                        best = max(best, dp[i][j-1][k] + coins[i][j]);

                        // using power
                        if(coins[i][j] < 0 && k > 0){
                            best = max(best, dp[i][j-1][k-1]);
                        }
                    }

                    dp[i][j][k] = best;
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};

int main() {

    return 0;
}