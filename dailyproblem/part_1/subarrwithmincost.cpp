#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int firstmin = 100, secondmin = firstmin;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < firstmin) {
                secondmin = firstmin;
                firstmin = nums[i];
            }
            else if (nums[i] > firstmin && nums[i] < secondmin) {
                secondmin = nums[i];
            }
        }
        return nums[0] + firstmin + secondmin;
    }
};

int main() {

    return 0;
}