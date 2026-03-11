#include <bits/stdc++.h>
using namespace std;

//longest subarr of 0 and 1 cnt same;

class Solution {
public:
    int maxLen(vector<int> &nums) {
        int zerocnt = 0, onecnt = 0;
        unordered_map<int, int> mp;
        int maxlen = 0;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            nums[i] == 0 ? zerocnt++ : onecnt++;
            int diff = zerocnt - onecnt;
            if(mp.count(diff)){
                maxlen = max(maxlen, i - mp[diff]);
            } else {    
                mp[diff] = i;
            }
        }
        return maxlen;
    }
};

int main() {

    return 0;
}