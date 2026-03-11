#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1, n = nums.size();
        while(j < n){
            while(j < n and nums[j] == nums[j-1]) j++;
            if(j >= n) break;
            nums[i++] = nums[j++];
        }
        return i;
    }
};

int main() {

    return 0;
}