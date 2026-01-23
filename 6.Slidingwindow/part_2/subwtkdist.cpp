#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int k){
        if(k < 0) return 0;
        unordered_map<int, int> mp;
        int l = 0, n = nums.size(), cnt = 0;
        for(int r = 0; r < n; r++){
            mp[nums[r]]++;
            while(mp.size() > k) {
                mp[nums[l]] == 1 ? mp.erase(nums[l]) : mp[nums[l]]--;
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};

int main() {

    return 0;
}