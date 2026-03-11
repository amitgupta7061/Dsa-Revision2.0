#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), lis = 1;
        vector<int> dp(n, 1), cnt(n, 1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                        lis = max(lis, dp[i]);
                    } else if(dp[j] + 1 == dp[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == lis) result += cnt[i];
        }
        return result;
    }
};

int main() {

    return 0;
}