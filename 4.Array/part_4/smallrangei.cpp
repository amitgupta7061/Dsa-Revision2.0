#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        int result = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            result = max(0, (maxi - mini) - 2*k);
        }
        return result;
    }
};

int main() {

    return 0;
}