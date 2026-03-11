#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dig(m+n-1);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int ind = j - i + (m - 1);
                if(dig[ind].size() && dig[ind].back() != matrix[i][j]) return false;
                dig[ind].push_back(matrix[i][j]);
            }
        }
        return true;
    }
};

int main(){

}