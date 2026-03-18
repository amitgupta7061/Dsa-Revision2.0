#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ispalindrome(string &s, int l, int r){
        while(l <= r){
            if(s[l] != s[r]) return false;
            else {l++; r--;};
        }
        return true;
    }
    int f(string &s, int ind, vector<int> &dp){
        if(ind == s.length()) return -1;
        if(dp[ind] != -1) return dp[ind];

        int mini = INT_MAX;
        for(int i = ind; i < s.length(); i++){
            if(ispalindrome(s, ind, i)){
                mini = min(mini, 1 + f(s, i+1, dp));
            }
        }
        return dp[ind] = mini;
    }
    int minCut(string s) {
        vector<int> dp(s.length(), -1);
        return f(s, 0, dp);
    }
};

class Solution {
public:
    int f(string &s, int ind, vector<int> &dp, vector<vector<bool>> &palindrome){
        if(ind == s.size()) return -1;
        if(dp[ind] != -1) return dp[ind];
        int mincut = INT_MAX;
        for(int i = ind; i < s.length(); i++){
            if(palindrome[ind][i]){
                mincut = min(mincut, 1 + f(s, i+1, dp, palindrome));
            }
        }
        return dp[ind] = mincut;
    }
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] and (j-i <= 2 or palindrome[i+1][j-1])){
                    palindrome[i][j] = true;
                }
            }
        }
        vector<int> dp(s.length(), -1);
        return f(s, 0, dp, palindrome);
    }
};

int main() {

    return 0;
}