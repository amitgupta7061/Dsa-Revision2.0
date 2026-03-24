#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n));

        dp[0][0] = {grid[0][0], grid[0][0]};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 and j == 0) continue;
                long long maxi = LLONG_MIN, mini = LLONG_MAX;
                if(i > 0){
                    auto [prevmax, prevmin] = dp[i-1][j];
                    maxi = max({maxi, prevmax * grid[i][j], prevmin * grid[i][j]});
                    mini = min({mini, prevmax * grid[i][j], prevmin * grid[i][j]});
                }
                if(j > 0){
                    auto [prevmax, prevmin] = dp[i][j-1];
                    maxi = max({maxi, prevmax * grid[i][j], prevmin * grid[i][j]});
                    mini = min({mini, prevmax * grid[i][j], prevmin * grid[i][j]});
                }
                dp[i][j] = {maxi, mini};
            }
        }

        long long res = dp[m-1][n-1].first;
        if(res < 0) return -1;

        return res % 1000000007;
    }
};

int main() {

    return 0;
}