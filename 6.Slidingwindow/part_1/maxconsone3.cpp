#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, zerocnt = 0, maxi = 0, n = nums.size();

        while(r < n){
            if(nums[r] == 1) r++;
            else if(zerocnt < k) {
                zerocnt++; r++;
            } else {
                maxi = max(maxi, r - l);
                while(nums[l] == 1) l++;
                l++; r++;
            }
        }
        maxi = max(maxi, r - l);
        return maxi;
    }
};

int main() {

    return 0;
}