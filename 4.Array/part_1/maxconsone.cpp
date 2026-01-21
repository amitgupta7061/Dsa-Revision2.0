#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currcnt = 0, maxcnt = 0;
        for(int num : nums){
            if(num == 1) currcnt++;
            else {
                maxcnt = max(maxcnt, currcnt);
                currcnt = 0;
            }
        }
        return maxcnt;
    }
};

int main() {

    return 0;
}