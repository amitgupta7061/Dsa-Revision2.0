#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool clockwise(vector<vector<int>> &mat, vector<vector<int>>& target, int n){
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        return mat == target;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;
        int n = mat.size();
        // 90 deg
        if(clockwise(mat, target, n)) return true;
        // 180 deg
        if(clockwise(mat, target, n)) return true;
        // 270 deg
        if(clockwise(mat, target, n)) return true;
        return false;
    }
};

int main() {

    return 0;
}