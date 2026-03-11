#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &cuts, int l, int r, vector<vector<int>> &dp){
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];

        int mini = INT_MAX;
        for(int i = l; i <= r; i++){
            int cost = cuts[r+1] - cuts[l-1] + f(cuts, l, i-1, dp) + f(cuts, i+1, r, dp);
            mini = min(mini, cost);
        }
        return dp[l][r] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return f(cuts, 1, m-2, dp);
    }
};

int main() {

    return 0;
}