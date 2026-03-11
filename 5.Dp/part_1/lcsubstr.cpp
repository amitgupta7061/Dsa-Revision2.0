#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubstr(string& s1, string& s2) {
        int m = s1.size(), n = s2.size(), result = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] += 1 + dp[i-1][j-1];
                    result = max(result, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        return result;
    }
};

int main() {

    return 0;
}