#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(vector<int> &nums, int ind, int target, vector<vector<int>> &dp){
        if(target < 0) return false;
        if(ind >= nums.size()) return target == 0;
        if(target == 0) return true;
        if(dp[ind][target] != -1) return dp[ind][target];
        return dp[ind][target] = f(nums, ind+1, target-nums[ind], dp) or f(nums, ind+1, target, dp);
    }
    bool equalPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2) return false;
        vector<vector<int>> dp(nums.size(), vector<int>((total/2)+1, -1));
        return f(nums, 0, total / 2, dp);
    }
};

int main() {

    return 0;
}