#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int low = 0, high = nums.size() - 1, floor = -1, ceil = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == x) {
                floor = ceil = nums[mid];
                break;
            }
            else if (nums[mid] < x) {
                floor = nums[mid];
                low = mid + 1;
            }
            else {
                ceil = nums[mid];
                high = mid - 1;
            }
        }
        return {floor, ceil};
    }
};


int main() {

    return 0;
}