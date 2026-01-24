#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long subarrayXor(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefixxor = 0, cnt = 0;
        for(int num : nums){
            prefixxor ^= num;
            if(mp.count(prefixxor ^ k)) cnt += mp[prefixxor ^ k];
            mp[prefixxor]++;
        }
        return cnt;
    }
};



int main() {

    return 0;
}