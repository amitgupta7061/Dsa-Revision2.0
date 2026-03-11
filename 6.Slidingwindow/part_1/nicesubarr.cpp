#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int k){
        if(k < 0) return 0;
        int l = 0, oddcnt = 0, n = nums.size(), cnt = 0;
        for(int r = 0; r < n; r++){
            if(nums[r] & 1) oddcnt++;
            while(oddcnt > k) {
                if(nums[l] & 1) oddcnt--;
                l++;
            } 
            cnt += r - l + 1;
        }
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};

int main() {

    return 0;
}