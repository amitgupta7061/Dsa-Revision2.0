#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    bool canpossible(vector<vector<int>> &mat, int k, int require){
        int cnt = 0, m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++){
            int low = 0, high = n-1, upperB = n;
            while(low <= high){
                int mid = (low + high) / 2;
                if(mat[i][mid] > k){
                    upperB = mid; high = mid - 1;
                }
                else low = mid + 1;
            }
            cnt += upperB;
        }
        return cnt <= require;
    }
    int median(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size(), low = INT_MAX, high = INT_MIN;
        for(int i = 0; i < m; i++){
            low = min(low, mat[i][0]);
            high = max(high, mat[i][n-1]);
        }
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canpossible(mat, mid, (m*n)/2)) low = mid + 1;
            else high = mid - 1;
        }  
        return low;  
    }
};

int main() {

    return 0;
}