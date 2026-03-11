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

int main() {

    return 0;
}