#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return true;
            else if(nums[mid] == nums[high]) high--;
            else if(nums[mid] < nums[high]){ // mid to end sorted
                if(target > nums[mid] and target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            } else {
                if(target >= nums[low] and target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
        }

        return false;
    }
};

int main() {

    return 0;
}