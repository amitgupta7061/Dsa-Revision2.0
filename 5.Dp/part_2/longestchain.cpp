#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canproceed(string &a, string &b){
        int m = a.size(), n = b.size();
        if(m + 1 != n) return false;
        int i = 0, j = 0;
        bool skipped = false;
        while(i < m && j < n){
            if(a[i] == b[j]){
                i++; j++;
            }
            else{
                if(skipped) return false;
                skipped = true;
                j++;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size(), lis = 1;
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(canproceed(words[j], words[i]) and dp[j]+1 > dp[i]){
                    dp[i] = 1 + dp[j];
                    lis = max(lis, dp[i]);
                }
            }
        }
        return lis;
    }
};

int main() {

    return 0;
}