#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        vector<int> prefix{1};
        int suffix = 1;

        for (auto& row : grid)
            for (int num : row)
                prefix.push_back((long long)prefix.back() * num % mod);

        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j) {
                ans[i][j] = prefix[i * n + j] * suffix % mod;
                suffix = (long long)suffix * grid[i][j] % mod;
            }

        return ans;
    }
};

int main() {

    return 0;
}