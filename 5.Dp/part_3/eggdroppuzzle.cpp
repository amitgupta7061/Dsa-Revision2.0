#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n, int k, vector<vector<int>> &dp){
        if(k == 0 or k == 1) return k;
        if(n == 1) return k;
        if(dp[n][k] != -1) return dp[n][k];
        int ans = INT_MAX;

        for(int i = 1; i <= k; i++){
            ans = min(ans, 1 + max(f(n-1, i-1, dp), f(n, k-i, dp)));
        }
        return dp[n][k] = ans;
    }
    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return f(n, k, dp);
    }
};

class Solution {
public:
    int f(int n, int k, vector<vector<int>> &dp){
        if(k == 0 || k == 1) return k;
        if(n == 1) return k;
        if(dp[n][k] != -1) return dp[n][k];

        int low = 1, high = k, ans = INT_MAX;

        while(low <= high){
            int mid = (low + high) / 2;
            int breakCase = f(n-1, mid-1, dp);
            int notBreakCase = f(n, k-mid, dp);

            ans = min(ans, 1 + max(breakCase, notBreakCase));

            if(breakCase < notBreakCase) low = mid + 1;
            else high = mid - 1;
        }

        return dp[n][k] = ans;
    }

    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return f(n, k, dp);
    }
};

class Solution {
public:
    int eggDrop(int eggs, int floors) {
        
        vector<long long> dp(eggs+1, 0);
        
        int moves = 0;
        
        while(dp[eggs] < floors){
            
            moves++;
            
            for(int e = eggs; e >= 1; e--){
                dp[e] = dp[e] + dp[e-1] + 1;
            }
        }
        
        return moves;
    }
};


int main() {

    return 0;
}