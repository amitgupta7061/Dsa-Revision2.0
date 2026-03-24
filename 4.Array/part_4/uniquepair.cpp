#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int, int> mp;

        for (int num : nums) {
            int rem = k - num;
            if(mp.count(rem)){
                cnt++;
                mp[rem]--;
            } else 
                mp[num]++;
        }

        return cnt;
    }
};

int main() {

    return 0;
}