#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canproceed(vector<int> &nums, int mid, int thresold){
        int sum = 0;
        for(int it : nums){
            sum += ceil((double)it / mid);
        }
        return sum <= thresold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canproceed(nums, mid, threshold)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

int main() {

    return 0;
}