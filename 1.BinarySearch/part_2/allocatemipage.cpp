#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canpossible(vector<int> &nums, int mid, int k){
        int cnt = 1, currsum = 0;
        for(int it : nums){
            if(currsum + it <= mid) currsum += it;
            else {
                cnt++; currsum = it;
            }
        }
        return cnt <= k;
    }
    int findPages(vector<int> &nums, int k) {
        if (k > nums.size()) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canpossible(nums, mid, k)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

int main() {

    return 0;
}