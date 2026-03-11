#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), lis = 1;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 and dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    lis = max(lis, dp[i]);
                }
            }
        }

        vector<int> result;
        int prev = -1;

        for(int i = n-1; i >= 0; i--){
            if(dp[i] == lis and (prev % nums[i] == 0 or prev == -1)){
                result.push_back(nums[i]);
                --lis;
                prev = nums[i];
            }
        }
        return result;
    }
};

int main() {

    return 0;
}