#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i > 0 and nums[i] == nums[i-1]) continue;
            int j = i + 1, k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while(j < k and nums[j] == nums[j-1]) j++;
                    while(j < k and nums[k] == nums[k+1]) k--;
                }
                else if(sum < 0) j++;
                else k--;
            }
        }

        return result;
    }
};

int main() {

    return 0;
}