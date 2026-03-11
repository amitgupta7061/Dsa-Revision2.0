#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstPos(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int lastPos(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target) ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return { firstPos(nums, target), lastPos(nums, target) };
    }
};


int main() {

    return 0;
}