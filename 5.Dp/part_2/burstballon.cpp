#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int l, int r, vector<vector<int>> &dp){
        if(l+1 >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        for(int i = l+1; i < r; i++){
            int cost = nums[l] * nums[i] * nums[r];
            cost += f(nums, l, i, dp) + f(nums, i, r, dp);
            ans = max(ans, cost);
        }
        return dp[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(nums, 0, n-1, dp);
    }
};

int main() {

    return 0;
}