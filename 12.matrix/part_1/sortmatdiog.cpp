#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> diagonal(m+n-1);

        for(int i = 0; i < m; i++){
            for(int j = n-1; j >= 0; j--){
                diagonal[i+j].push_back(mat[i][j]);
            }
        }

        for(int i = 0; i < diagonal.size(); i++){
            sort(diagonal[i].begin(), diagonal[i].end());
        }

        vector<int> idx(m+n-1,0);

        for(int i = 0; i < m; i++){
            for(int j = n-1; j >= 0; j--){
                mat[i][j] = diagonal[i+j][idx[i+j]++];
            }
        }

        return mat;
    }
};

int main() {

    return 0;
}