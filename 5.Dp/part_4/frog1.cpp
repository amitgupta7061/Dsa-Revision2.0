#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int f(vector<int> &heights, int ind, vector<int> &dp){
        if(ind == heights.size()-1) return 0;
        if(dp[ind] != -1) return dp[ind];

        int takeonestep = abs(heights[ind+1] - heights[ind]) + f(heights, ind+1, dp);
        int taketwostep = ind+2 < heights.size() ? abs(heights[ind+2] - heights[ind]) + f(heights, ind+2, dp) : INT_MAX;

        return dp[ind] = min(takeonestep, taketwostep);
    }
    int minCostJump(vector<int> &heights){
        vector<int> dp(heights.size(), -1);
        return f(heights, 0, dp);
    }
};

int main() {

    int n;
    cin >> n;
    vector<int> heights(n);
    for(auto &it : heights) cin >> it;

    Solution sol;
    cout<<sol.minCostJump(heights);

    return 0;
}