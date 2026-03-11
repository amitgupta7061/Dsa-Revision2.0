#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumTriangles(vector<vector<int>>& mat) {
        int n = mat.size();
        int usum = 0, lsum = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                usum += mat[j][i];
                lsum += mat[i][j];
            }
        }
        return {usum, lsum};
    }
};


int main(){

}