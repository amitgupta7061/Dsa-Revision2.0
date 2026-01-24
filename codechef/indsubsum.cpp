#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> subarraySum(vector<int> &nums, int k) {
        unordered_map<long long, int> mp;
        mp[0] = -1;

        long long currsum = 0;

        for(int r = 0; r < nums.size(); r++){
            currsum += nums[r];

            if(mp.count(currsum - k)){
                return {mp[currsum - k] + 2, r + 1};
            }

            if(!mp.count(currsum))
                mp[currsum] = r;
        }
        return {-1};
    }
};


int main() {

    return 0;
}