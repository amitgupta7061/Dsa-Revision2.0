#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = 0, l = 0, maxi = -1;

        for(int r = 0; r < n; r++){
            while(l < n and nums[r] > (long long)k*nums[l]) l++;
            maxi = max(maxi, r - l + 1);
        }
        return n - maxi;
    }
};

int main() {

    return 0;
}