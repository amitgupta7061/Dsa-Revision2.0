#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 0; i < numRows; i++){
            vector<int> rows(i+1);
            for(int j = 0; j <= i; j++){
                if(j == 0 or j == i) rows[j] = 1;
                else rows[j] = result[i-1][j] + result[i-1][j-1];
            }
            result.push_back(rows);
        }
        return result;
    }
};

int main() {

    return 0;
}