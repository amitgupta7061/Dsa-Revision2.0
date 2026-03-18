#include <bits/stdc++.h>
using namespace std;

// mcm code 
class Solution {
public:
    int f(vector<int> &nums, int l, int r){
        if(l == r) return 0;

        int mini = INT_MAX;
        for(int k = l; k < r; k++){
            int lft = f(nums, l, k);
            int rgt = f(nums, k+1, r);
            int curr = nums[l-1] * nums[k] * nums[r];

            mini = min(mini, lft + rgt + curr);
        }
        return mini;
    }

    int matrixMultiplication(vector<int>& nums){
        int n = nums.size();
        return f(nums, 1, n-1);
    }
};

// cut stick
class Solution {
public:
    int f(vector<int> &cuts, int l, int r){
        if(l > r) return 0;

        int mini = INT_MAX;
        for(int k = l; k <= r; k++){
            int lft = f(cuts, l, k-1);
            int rgt = f(cuts, k+1, r);
            int cost = cuts[r+1] - cuts[l-1];

            mini = min(mini, lft + rgt + cost);
        }
        return mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        return f(cuts, 1, cuts.size()-2);
    }
};

//burst baloon
class Solution {
public:
    int f(vector<int> &nums, int l, int r){
        if(l > r) return 0;

        int maxi = 0;
        for(int k = l; k <= r; k++){
            int lft = f(nums, l, k-1);
            int rgt = f(nums, k+1, r);
            int curr = nums[l-1] * nums[k] * nums[r+1];

            maxi = max(maxi, lft + rgt + curr);
        }
        return maxi;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return f(nums, 1, nums.size()-2);
    }
};

int main() {

    return 0;
}