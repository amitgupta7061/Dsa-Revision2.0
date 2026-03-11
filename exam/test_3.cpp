#include <bits/stdc++.h>
using namespace std;

// Question - 1 Monica and Offers
int maxGoods(int n, long long p, vector<int>& price) {
    sort(price.begin(), price.end());
    vector<long long> dp(n + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + price[i - 1];
        if (i >= 2) dp[i] = min(dp[i], dp[i - 2] + price[i - 1]);
    }

    for (int i = n; i >= 0; i--) {
        if (dp[i] <= p) return i;
    }

    return 0;
}

// Question - 2 Chocolates Pickup
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

// Question - 3 Count Square Submatrices with All Ones
int countSquare(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size(), total = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1 and i > 0 && j > 0) {
                matrix[i][j] = 1 + min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]});
            }
            total += matrix[i][j];
        }
    }

    return total;
}

// Question - 4 Wildcard Matching
int wildcardMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == s[i - 1] or p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*') dp[i][j] = dp[i][j - 1] or dp[i - 1][j];
            else dp[i][j] = false;
        }
    }

    return dp[n][m];
}

// Question - 5 Longest Bitonic Subsequence
int longestBitonicSequence(vector<int> &nums) {
    int n= nums.size();
    vector<int> lis(n, 1), lds(n, 1);

    for(int i = 0; i < n; i++){  // lis
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    for(int i = n - 1; i >= 0; i--){ // lds
        for(int j = n - 1; j > i; j--){
            if(nums[i] > nums[j]){
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int result = 0;

    for(int i = 0; i < n; i++){
        if(lis[i] > 1 && lds[i] > 1){
            result = max(result, lis[i] + lds[i] - 1);
        }
    }

    return result;
}

int main() {

    return 0;
}