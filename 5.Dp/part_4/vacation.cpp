#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp) {
        if(day == arr.size()) return 0;
        if(dp[day][last] != -1) return dp[day][last];
        int ans = 0;
        if(last != 0) {
            ans = max(ans, arr[day][0] + f(day+1, 0, arr, dp));
        }
        if(last != 1) {
            ans = max(ans, arr[day][1] + f(day+1, 1, arr, dp));
        }
        if(last != 2) {
            ans = max(ans, arr[day][2] + f(day+1, 2, arr, dp));
        }
        return dp[day][last] = ans;
    }

    int maxHappiness(vector<vector<int>> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(0, 3, arr, dp);
    }
};

int main() {
    int N;
    cin >> N;

    vector<vector<int>> arr(N, vector<int>(3));
    for(int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    Solution sol;
    cout << sol.maxHappiness(arr);

    return 0;
}
