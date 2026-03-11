#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int ind, int k, vector<int> &dp){
        if(ind >= nums.size()) return 0;
        if(dp[ind] != -1) return dp[ind];

        int currmaxi = -1, maxi = 0;
        for(int j = ind; j < nums.size() && j-ind+1 <= k; j++){
            currmaxi = max(currmaxi, nums[j]);
            maxi = max(maxi, currmaxi*(j-ind+1) + f(nums, j+1, k, dp));
        }
        return dp[ind] = maxi;
    }
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), -1);
        return f(nums, 0, k, dp);
    }
};

int main() {

    return 0;
}