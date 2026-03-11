#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] += 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

int lcs(string &s1, string &s2) {
    int m = s1.length(), n = s2.length();
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= m; ++i) {
        int prev = dp[0];
        for (int j = 1; j <= n; ++j) {
            int temp = dp[j];
            if (s1[i - 1] == s2[j - 1]) dp[j] = 1 + prev;
            else dp[j] = max(dp[j - 1], dp[j]);
            prev = temp;
        }
    }
    return dp[n];
}

int main() {

    return 0;
}