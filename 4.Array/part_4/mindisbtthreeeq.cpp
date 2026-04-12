#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, queue<int>> mp;
        int n = nums.size();
        int mini = -1;

        for(int i = 0; i < n; i++){
            if(mp.count(nums[i])){
                if(mp[nums[i]].size() == 2){
                    int fst = mp[nums[i]].front(); mp[nums[i]].pop();
                    int scd = mp[nums[i]].front(); mp[nums[i]].pop();

                    mini = min(mini, abs(fst-scd) + abs(scd - i) + abs(i - fst));
                    mp[nums[i]].push(scd);
                }
            }
            mp[nums[i]].push(i);
        }

        return mini;
    }
};

int main() {

    return 0;
}