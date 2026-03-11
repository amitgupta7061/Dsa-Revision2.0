#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countDistinct(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        vector<int> result;
        int l = 0, r = 0;
        while(r < k) mp[nums[r++]]++;
        result.push_back(mp.size());
        while(r < nums.size()){
            mp[nums[l]] == 1 ? mp.erase(nums[l]) : mp[nums[l]]--;
            mp[nums[r]]++;
            result.push_back(mp.size());
            r++; l++;
        }
        return result;
    }
};

int main() {

    return 0;
}