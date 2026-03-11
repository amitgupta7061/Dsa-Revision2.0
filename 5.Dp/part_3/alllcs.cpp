#include <bits/stdc++.h>
using namespace std;

class Solution{
    map<pair<int, int>, set<string>> memo;
public:
    set<string> backtrack(string &s1, string &s2, int n, int m, vector<vector<int>> &dp){
        if (n == 0 || m == 0) return {""};
        if (memo.count({n, m})) return memo[{n, m}];

        set<string> res;
        if (s1[n - 1] == s2[m - 1]){
            set<string> temp = backtrack(s1, s2, n - 1, m - 1, dp);
            for (const string &s : temp) res.insert(s + s1[n - 1]);
        }
        else{
            if (dp[n - 1][m] == dp[n][m]){
                set<string> temp = backtrack(s1, s2, n - 1, m, dp);
                res.insert(temp.begin(), temp.end());
            }
            if (dp[n][m - 1] == dp[n][m]){
                set<string> temp = backtrack(s1, s2, n, m - 1, dp);
                res.insert(temp.begin(), temp.end());
            }
        }
        return memo[{n, m}] = res;
    }

    vector<string> allLCS(string s1, string s2){
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        memo.clear();
        set<string> st = backtrack(s1, s2, n, m, dp);

        return vector<string>(st.begin(), st.end());
    }
};