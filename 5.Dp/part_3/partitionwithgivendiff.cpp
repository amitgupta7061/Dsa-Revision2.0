#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int ind, int target, vector<vector<int>> &dp){
        if(ind >= nums.size()) return target == 0;
        if(dp[ind][target] != -1) return dp[ind][target];
        int ans = f(nums, ind+1, target, dp);
        if(target >= nums[ind]) ans += f(nums, ind+1, target-nums[ind], dp);
        return dp[ind][target] = ans;
    }
    int countPartitions(vector<int>& nums, int diff) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum + diff) % 2) return 0;
        vector<vector<int>> dp(n, vector<int>(((sum + diff) / 2)+1, -1));
        return f(nums, 0, (sum + diff) / 2, dp);
    }
};

int main() {

    return 0;
}