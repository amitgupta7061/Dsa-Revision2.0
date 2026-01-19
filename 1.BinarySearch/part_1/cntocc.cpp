#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstocc(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            } 
            else if (nums[mid] < target)  low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }

    int lastocc(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            } 
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }

    int countFreq(vector<int>& nums, int target) {
        int first = firstocc(nums, target);
        if (first == -1) return 0; 

        int last = lastocc(nums, target);
        return last - first + 1;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 3, 3};
    cout<<sol.countFreq(nums, 1);
    return 0;
}