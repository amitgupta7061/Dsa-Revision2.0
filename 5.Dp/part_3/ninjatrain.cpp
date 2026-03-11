#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(3));
        for(int j = 0; j < 3; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < 3; j++){
                int maxi = 0;
                for(int k = 0; k < 3; k++){
                    if(k != j){
                        maxi = max(maxi, dp[i-1][k]);
                    }
                }
                dp[i][j] = matrix[i][j] + maxi;
            }
        }

        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};


int main() {

    return 0;
}