#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        unordered_map<long long, int> mp;
        mp[0] = -1;
        long long curr = 0;
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            if(!mp.count(curr)) mp[curr] = i;

            long long rem = curr - k;
            if(mp.count(rem)) maxi = max(maxi, i-mp[rem]);
        }
        return maxi;
    }
};


int main() {

    return 0;
}