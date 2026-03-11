#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0], currmaxi = nums[0], currmini = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0) swap(currmaxi, currmini);
            currmaxi = max(nums[i], currmaxi * nums[i]);
            currmini = min(nums[i], currmini * nums[i]);
            maxi = max(maxi, currmaxi);
        }

        return maxi;
    }
};

int main() {

    return 0;
}