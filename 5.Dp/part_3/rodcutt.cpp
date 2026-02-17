#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &price, int n, vector<int> &dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int maxi = 0;
        for(int i = 1; i <= n; i++){
            maxi = max(maxi, price[i-1]+f(price, n-i, dp));
        }
        return dp[n] = maxi;
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n+1, -1);
        return f(price, n, dp);
    }
};

int main() {

    return 0;
}