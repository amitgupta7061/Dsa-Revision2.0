#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int currsum = 0, maxsum = INT_MIN;
        int start = 0, ansstart = 0, ansend = 0;

        for(int i = 0; i < nums.size(); i++){
            if(currsum == 0) start = i;
            
            currsum += nums[i];

            if(currsum > maxsum){
                maxsum = currsum;
                ansstart = start;
                ansend = i;
            }

            if(currsum < 0) currsum = 0;
        }

        vector<int> result;
        for(int i = ansstart; i <= ansend; i++) result.push_back(nums[i]);
        return result;
    }
};

int main() {

    return 0;
}