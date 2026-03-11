#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), cnt = 0;
        int s_row = 0, l_row = m - 1, s_col = 0, l_col = n - 1;
        vector<int> result;
        while(cnt < m*n) {
            for(int i = s_col; i <= l_col; i++){
                result.push_back(matrix[s_row][i]); cnt++;
            }
            if(cnt >= m*n) break;
            s_row++;
            for(int i = s_row; i <= l_row; i++){
                result.push_back(matrix[i][l_col]); cnt++;
            }
            if(cnt >= m*n) break;
            l_col--;
            for(int i = l_col; i >= s_col; i--){
                result.push_back(matrix[l_row][i]); cnt++;
            }
            if(cnt >= m*n) break;
            l_row--;
            for(int i = l_row; i >= s_row; i--){
                result.push_back(matrix[i][s_col]); cnt++;
            }
            s_col++;
        } 
        return result;
    }
};

int main() {

    return 0;
}