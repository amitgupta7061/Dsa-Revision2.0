#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long f(int ind, int W, vector<int> &wt, vector<long long> &val, vector<vector<long long>> &dp) {
        if(ind == wt.size()) return 0;

        if(dp[ind][W] != -1) return dp[ind][W];

        long long nottake = f(ind+1, W, wt, val, dp);

        long long take = 0;
        if(wt[ind] <= W) {
            take = val[ind] + f(ind+1, W - wt[ind], wt, val, dp);
        }

        return dp[ind][W] = max(take, nottake);
    }

    long long knapsack(int N, int W, vector<int> &wt, vector<long long> &val) {
        vector<vector<long long>> dp(N, vector<long long>(W+1, -1));
        return f(0, W, wt, val, dp);
    }
};

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> wt(N);
    vector<long long> val(N);

    for(int i = 0; i < N; i++) {
        cin >> wt[i] >> val[i];
    }

    Solution sol;
    cout << sol.knapsack(N, W, wt, val);

    return 0;
}
