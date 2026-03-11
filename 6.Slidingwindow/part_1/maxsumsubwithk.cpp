#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return -1;

        int currsum = 0;
        for (int i = 0; i < k; i++) currsum += nums[i];
        int maxi = currsum;
        for (int i = k; i < n; i++) {
            currsum += nums[i]; 
            currsum -= nums[i - k];
            maxi = max(maxi, currsum);
        }

        return maxi;
    }
};


int main() {

    return 0;
}