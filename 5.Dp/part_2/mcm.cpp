#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int f(vector<int> &nums, int l, int r, vector<vector<int>> &dp){
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int mini = INT_MAX;

        for(int i = l; i < r; i++){
            int left = f(nums, l, i, dp);
            int rght = f(nums, i+1, r, dp);
            int curr = nums[l-1] * nums[i] * nums[r];
            mini = min(mini, curr+left+rght);
        }
        return dp[l][r] = mini;
    }
    int matrixMultiplication(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(nums, 1, n-1, dp);
    }
};

int main() {

    return 0;
}