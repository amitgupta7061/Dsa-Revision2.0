#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;

        int i = n - 2;
        while(i >= 0 and nums[i] >= nums[i+1]) i--;

        if(i >= 0){
            int j = n - 1;
            while(nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin()+i+1, nums.end());
    }
};


int main() {

    return 0;
}