#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), xr = 0;
        for(int i = 0; i <= n; i++) xr ^= i;

        for(int num : nums) xr ^= num;

        return xr;
    }
};

int main() {

    return 0;
}