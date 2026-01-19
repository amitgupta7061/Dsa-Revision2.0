#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canproceed(vector<int> &nums, int mid, int k){
        int cnt = 1, currsum = 0;
        for(int num : nums){
            if(currsum + num <= mid) currsum += num;
            else {
                cnt++; currsum = num;
            }
        }
        return cnt <= k;
    }
    int minTime(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canproceed(nums, mid, k)) {
                high = mid - 1;
            } else low = mid + 1;
        }
        return low;
    }
};

int main() {

    return 0;
}