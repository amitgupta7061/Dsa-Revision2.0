#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = nums[0];
        for(int i = 1; i < nums.size(); i++){
            xr = xr ^ nums[i];
        }
        return xr;
    }
};

int main() {

    return 0;
}