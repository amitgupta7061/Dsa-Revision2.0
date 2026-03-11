#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string lcs(string &s1, string &s2){
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int i = m, j = n;
        string ans = "";

        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    Solution sol;
    cout<<sol.lcs(s1, s2);

    return 0;
}