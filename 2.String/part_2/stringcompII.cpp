#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(const string& s, int ind, int k, vector<vector<int>> &dp) {
        if (k < 0) return 101;
        if (ind == s.length() || s.length() - ind <= k) return 0;
        if (dp[ind][k] != 101)  return dp[ind][k];
      
        vector<int> charCnt(128, 0);
        int maxi = 0;
      
        for (int end = ind; end < s.length(); end++) {
            charCnt[s[end]]++;
            maxi = max(maxi, charCnt[s[end]]);
          

            int len = end - ind + 1, delcnt = len - maxi;
            int cnt = maxi == 1 ? 1 : maxi < 10 ? 2 : maxi < 100 ? 3 : 4;
          
            int total = cnt + f(s, end + 1, k - delcnt, dp);
          
            dp[ind][k] = min(dp[ind][k], total);
        }
      
        return dp[ind][k];
    }
    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(s.length(), vector<int>(k + 1, 101));
        return f(s, 0, k, dp);
    }
};


int main() {

    return 0;
}