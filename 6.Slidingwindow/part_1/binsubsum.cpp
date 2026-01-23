#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int goal){
        if(goal < 0) return 0;
        int l = 0, n = nums.size(), cnt = 0, curr = 0;
        for(int r = 0; r < n; r++){
            curr += nums[r];
            while(curr > goal) curr -= nums[l++];
            cnt += r-l+1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal) - f(nums, goal-1);
    }
};

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currsum = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            currsum += nums[i];
            if(mp.count(currsum-goal)) cnt += mp[currsum-goal];
            mp[currsum]++;
        }
        return cnt;
    }
};

int main() {

    return 0;
}