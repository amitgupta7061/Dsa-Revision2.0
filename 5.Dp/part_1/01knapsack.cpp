#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &val, vector<int> &wt, int ind, int w, vector<vector<int>> &dp){
        if(ind >= val.size()) return 0;
        if(w <= 0) return 0;
        if(dp[ind][w] != -1) return dp[ind][w];
        int take = 0;
        if(w >= wt[ind]) take += val[ind] + f(val, wt, ind+1, w-wt[ind], dp);
        int nottake = f(val, wt, ind+1, w, dp);
        return dp[ind][w] = max(take, nottake);
    }
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(val.size(), vector<int>(w+1, -1));
        return f(val, wt, 0, w, dp);
    }
};

int main() {

    return 0;
}