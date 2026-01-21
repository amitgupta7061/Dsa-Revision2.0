#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int maxi = 0, currsum = 0;
        for(int i = 0; i < nums.size(); i++){
            currsum += nums[i];
            if(mp.count(currsum)) maxi = max(maxi, i - mp[currsum]);
            else mp[currsum] = i;
        }
        return maxi;
    }
};

int main() {

    return 0;
}