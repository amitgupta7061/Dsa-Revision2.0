#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, cand1 = 0, cand2 = 0;
        for(int num : nums){
            if(num == cand1) cnt1++;
            else if(num == cand2) cnt2++;
            else if(cnt1 == 0) { cand1 = num; cnt1++;}
            else if(cnt2 == 0) { cand2 = num; cnt2++; }
            else { cnt1--; cnt2--; }
        }

        cnt1 = cnt2 = 0;
        for(int num : nums){
            num == cand1 ? cnt1++ : num == cand2 ? cnt2++ : 0 ;
        }
        vector<int> result;
        if(cnt1 > nums.size()/3) result.push_back(cand1);
        if(cnt2 > nums.size()/3) result.push_back(cand2);
        return result;
    }
};

int main() {

    return 0;
}