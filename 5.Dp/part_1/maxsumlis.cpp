#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int ind, int prev, vector<vector<int>> &dp){
        if(ind >= nums.size()) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int take = 0;
        if(prev == -1 or nums[ind] > nums[prev]){
            take = nums[ind] + f(nums, ind+1, ind, dp);
        }
        int nottake = f(nums, ind+1, prev, dp);
        return dp[ind][prev+1] = max(take, nottake);
    }
    int maxSumIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return f(nums, 0, -1, dp);
    }
};

int main() {

    return 0;
}