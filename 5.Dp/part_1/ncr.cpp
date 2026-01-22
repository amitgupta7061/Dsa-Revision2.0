#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n, int r, vector<vector<int>> &dp){
        if(r > n) return 0;
        if(r == 0 or r == n) return 1;
        if(dp[n][r] != -1) return dp[n][r];
        return dp[n][r] = f(n-1, r-1, dp) + f(n-1, r, dp);
    }
    int nCr(int n, int r) {
        vector<vector<int>> dp(n+1, vector<int>(r+1, -1));
        return f(n, r, dp);
    }
};

int main() {

    return 0;
}