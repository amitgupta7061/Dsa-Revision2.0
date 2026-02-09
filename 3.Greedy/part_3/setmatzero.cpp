#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        bool firstrow = false, firstcol = false;
        for(int i = 0; i < m; i++) if(mat[i][0] == 0) firstcol = true;
        for(int j = 0; j < n; j++) if(mat[0][j] == 0) firstrow = true;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(mat[i][j] == 0){
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(mat[i][0] == 0 || mat[0][j] == 0){
                    mat[i][j] = 0;
                }
            }
        }
        if(firstrow){
            for(int j = 0; j < n; j++) mat[0][j] = 0;
        }
        if(firstcol){
            for(int i = 0; i < m; i++) mat[i][0] = 0;
        }
    }
};

int main() {

    return 0;
}