#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int f(vector<vector<int>> &grid, int r, int ac, int bc){
        if(ac < 0 or bc < 0 or ac >= n or bc >= n) return INT_MIN;
        if(r == m - 1){
            if(ac == bc) return grid[r][ac];
            else return grid[r][ac] + grid[r][bc];
        }
        int curr;

        if(ac == bc) curr = grid[r][ac];
        else curr = grid[r][ac] + grid[r][bc];
        int best = INT_MIN;
        for(int da = -1; da <= 1; da++){
            for(int db = -1; db <= 1; db++){
                int next = f(grid, r + 1, ac + da, bc + db);
                best = max(best, next);
            }
        }
        return curr + best;
    }

    int maxChocolates(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        return f(grid, 0, 0, n - 1);
    }
};

int main() {
    return 0;
}
