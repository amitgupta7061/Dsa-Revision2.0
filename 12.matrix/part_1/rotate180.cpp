#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        reverse(mat.begin(), mat.end());
        for(int i = 0; i < m; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
};


int main() {

    return 0;
}