#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int ind, int cnt, int sum1, int n, int totalSum, vector<vector<unordered_map<int,int>>>& dp) {
        if (ind == nums.size()) {
            if (cnt == n) return abs(totalSum - 2 * sum1);
            return 1e9;
        }
        if (dp[ind][cnt].count(sum1)) return dp[ind][cnt][sum1];
        int take = 1e9, notTake;
        if (cnt < n) take = f(nums, ind + 1, cnt + 1, sum1 + nums[ind], n, totalSum, dp);
        notTake = f(nums, ind + 1, cnt, sum1, n, totalSum, dp);
        return dp[ind][cnt][sum1] = min(take, notTake);
    }

    int minimumDifference(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size() / 2;
        vector<vector<unordered_map<int,int>>> dp(nums.size(), vector<unordered_map<int,int>>(n + 1));
        return f(nums, 0, 0, 0, n, totalSum, dp);
    }
};



class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> left(n + 1), right(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int sumL = 0, sumR = 0, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sumL += nums[i];
                    sumR += nums[i + n];
                    cnt++;
                }
            }
            left[cnt].push_back(sumL);
            right[cnt].push_back(sumR);
        }

        for (int i = 0; i <= n; i++) sort(right[i].begin(), right[i].end());

        int ans = INT_MAX;

        for (int k = 0; k <= n; k++) {
            for (int s1 : left[k]) {
                int target = total / 2 - s1;
                auto &vec = right[n - k];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) ans = min(ans, abs(total - 2 * (s1 + *it)));
                if (it != vec.begin()) {
                    --it;
                    ans = min(ans, abs(total - 2 * (s1 + *it)));
                }
            }
        }

        return ans;
    }
};


int main() {

    return 0;
}