#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int num){
        for(int i = 1; i < 32; i++){
            if(num & (1 << i)) continue;
            else return num ^ (1 << (i-1));
        }
        return -1;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 2) result.push_back(-1);
            else result.push_back(f(nums[i]));
        }
        return result;
    }
};

int main() {

    return 0;
}