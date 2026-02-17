#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size(), maxi = 1;
        vector<int> dp(n, 1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(envelopes[j][0] < envelopes[i][0] and envelopes[j][1] < envelopes[i][1]) dp[i] = max(dp[i], dp[j]+1);
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
            [](vector<int>& a, vector<int>& b){
                if(a[0] == b[0]) return a[1] > b[1];
                return a[0] < b[0];
            });

        vector<int> lis;

        for(auto &env : envelopes){
            int h = env[1];
            auto it = lower_bound(lis.begin(), lis.end(), h);

            if(it == lis.end()) lis.push_back(h);
            else *it = h;
        }

        return lis.size();
    }
};


int main() {

    return 0;
}