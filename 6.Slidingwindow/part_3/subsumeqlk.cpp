#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cntSubarrays(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currsum = 0, cnt = 0;
        for(int r = 0; r < nums.size(); r++){
            currsum += nums[r];
            if(mp.count(currsum - k)){
                cnt += mp[currsum - k];
            }
            mp[currsum]++;
        }
        return cnt;
    }
};

int main() {

    return 0;
}