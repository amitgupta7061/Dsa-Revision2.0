#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getLIS(vector<int>& nums) {
        int n = nums.size(), lis = 1;
        vector<int> dp(n, 1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j]+1);
            }
            lis = max(lis, dp[i]);
        }

        vector<int> result;
        int prev = -1;

        for(int i = n-1; i >= 0; i--){
            if(dp[i] == lis and (prev == -1 or prev > nums[i])){
                result.push_back(nums[i]);
                lis--;
                prev = nums[i];
            }
        }
        reverse(result.begin(), result.end());

        return result;
    }
};

class Solution {
public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        
        int maxLen = 1, lastIndex = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> lis;
        while(parent[lastIndex] != lastIndex){
            lis.push_back(arr[lastIndex]);
            lastIndex = parent[lastIndex];
        }
        lis.push_back(arr[lastIndex]);
        reverse(lis.begin(), lis.end());
        
        return lis;
    }
};

int main() {

    return 0;
}