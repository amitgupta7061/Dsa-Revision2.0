#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int p = s1.size(), q = s2.size(), r = s3.size();
        vector<vector<vector<int>>> dp(p+1, vector<vector<int>>(q+1, vector<int>(r+1, 0)));
        for(int i = 1; i <= p; i++){
            for(int j = 1; j <= q; j++){
                for(int k = 1; k <= r; k++){
                    if(s1[i-1] == s2[j-1] and s2[j-1] == s3[k-1]) dp[i][j][k] += 1 + dp[i-1][j-1][k-1];
                    else dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]);
                }
            }
        }
        return dp[p][q][r];
    }
};

class Solution {
public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int p = s1.size(), q = s2.size(), r = s3.size();
        
        int dp[101][101][101] = {0};
        
        for(int i = 1; i <= p; i++) {
            for(int j = 1; j <= q; j++) {
                for(int k = 1; k <= r; k++) {
                    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                    else dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                }
            }
        }
        return dp[p][q][r];
    }
};


int main() {

    return 0;
}