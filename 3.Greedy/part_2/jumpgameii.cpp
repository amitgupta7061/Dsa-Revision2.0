#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi = 0, cnt = 0, currpos = 0;
        for(int i = 0; i < nums.size()-1; i++){
            maxi = max(maxi, i+nums[i]);
            if(i == currpos){
                cnt++; currpos = maxi;
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}