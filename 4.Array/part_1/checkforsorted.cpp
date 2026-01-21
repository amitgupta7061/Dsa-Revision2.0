#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > nums[(i+1) % n]) cnt++;
        }
        return cnt <= 1;
    }
};

int main() {

    return 0;
}