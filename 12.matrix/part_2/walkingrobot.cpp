#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        int x = 0;
        int y = 0;
        int res = 0;

        set<pair<int, int>> st;
        for (auto& o : obstacles) {
            st.insert({o[0], o[1]});
        }

        for (int c : commands) {
            if (c == -2) {
                d = (d + 3) % 4;
            } else if (c == -1) {
                d = (d + 1) % 4;
            } else {
                for (int i = 0; i < c; i++) {
                    int nx = x + dirs[d].first;
                    int ny = y + dirs[d].second;
                    if (st.count({nx, ny}))
                        break;
                    x = nx;
                    y = ny;
                    res = max(res, x * x + y * y);
                }
            }
        }

        return res;
    }
};

int main() {

    return 0;
}