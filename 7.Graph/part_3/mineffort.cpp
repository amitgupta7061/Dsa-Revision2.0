#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while(!pq.empty()){
            auto [diff, r, c] = pq.top(); pq.pop();
            if(r == m-1 and c == n-1) return diff;

            if(visited[r][c]) continue;
            visited[r][c] = true;

            for(auto [dx, dy] : directions){
                int nr = r + dx, nc = c + dy;
                if(nr >= 0 and nc >= 0 and nr < m and nc < n and !visited[nr][nc]){
                    int newdiff = max(diff, abs(heights[nr][nc] - heights[r][c]));
                    pq.push({newdiff, nr, nc});
                }
            }
        }
        return -1;
    }
};

int main() {

    return 0;
}