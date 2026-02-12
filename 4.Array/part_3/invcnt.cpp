#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long merge(vector<int> &nums, int l, int m, int r){
        vector<int> temp;
        int i = l, j = m + 1;
        long long cnt = 0;

        while(i <= m and j <= r){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
                cnt += (m - i + 1);
            }
        }
        while(i <= m) temp.push_back(nums[i++]);
        while(j <= r) temp.push_back(nums[j++]);

        for(int k = l; k <= r; k++){
            nums[k] = temp[k-l];
        }
        return cnt;
    }
    long long mergesort(vector<int> &nums, int l, int r){
        long long cnt = 0;
        if(l < r){
            int mid = l + (r - l) / 2;
            cnt += mergesort(nums, l, mid);
            cnt += mergesort(nums, mid+1, r);
            cnt += merge(nums, l, mid, r);
        }
        return cnt;
    }
    int inversionCount(vector<int> &nums) {
        return mergesort(nums, 0, nums.size()-1);
    }
};

int main() {

    return 0;
}