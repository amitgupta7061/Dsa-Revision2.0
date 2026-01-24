#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestSubarrayDivK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int maxi = 0;
        long long currsum = 0;

        mp[0] = -1;

        for (int r = 0; r < nums.size(); r++) {
            currsum += nums[r];
            int rem = (currsum % k + k) % k;

            if (mp.count(rem)) {
                maxi = max(maxi, r - mp[rem]);
            } else {
                mp[rem] = r;
            }
        }
        return maxi;
    }
};


int main() {

    return 0;
}