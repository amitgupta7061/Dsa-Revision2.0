#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = 0, cnt = 0;
        for(int num : nums){
            if(cnt == 0) cand = num;
            if(num == cand) cnt++;
            else cnt--;
        }
        return cand;
    }
};

int main() {

    return 0;
}