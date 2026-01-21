#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
    }
};

class Solution {
public:
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l++], nums[r--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};


int main() {

    return 0;
}