#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n, int cnt, int size, vector<vector<int>> &dp) {
        if (cnt < 0 || cnt > n || size > 2*n) return 0;
        if (size == 2*n) return (cnt == 0);
        if(dp[cnt][size] != -1) return dp[cnt][size];
        return dp[cnt][size] = f(n, cnt + 1, size + 1, dp) + f(n, cnt - 1, size + 1, dp);
    }

    int findCatalan(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n*2, -1));
        return f(n, 0, 0, dp);
    }
};



int main() {

    return 0;
}