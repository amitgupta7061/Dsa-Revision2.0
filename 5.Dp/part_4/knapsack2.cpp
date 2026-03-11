#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long f(int ind, int value, vector<int> &wt, vector<int> &val, vector<vector<long long>> &dp) {
        if(value == 0) return 0;
        if(ind == wt.size()) return LLONG_MAX;

        if(dp[ind][value] != -1) return dp[ind][value];

        long long nottake = f(ind+1, value, wt, val, dp);

        long long take = LLONG_MAX;
        if(val[ind] <= value) {
            long long sub = f(ind+1, value - val[ind], wt, val, dp);
            if(sub != LLONG_MAX) take = wt[ind] + sub;
        }

        return dp[ind][value] = min(take, nottake);
    }

    long long knapsack(int N, long long W, vector<int> &wt, vector<int> &val) {
        int maxValue = accumulate(val.begin(), val.end(), 0);

        vector<vector<long long>> dp(N, vector<long long>(maxValue+1, -1));

        long long ans = 0;

        for(int v = 0; v <= maxValue; v++) {
            long long requiredWeight = f(0, v, wt, val, dp);
            if(requiredWeight <= W) ans = v;
        }

        return ans;
    }
};

int main() {
    int N;
    long long W;
    cin >> N >> W;

    vector<int> wt(N), val(N);
    for(int i = 0; i < N; i++) {
        cin >> wt[i] >> val[i];
    }

    Solution sol;
    cout << sol.knapsack(N, W, wt, val);

    return 0;
}
