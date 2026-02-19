#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;

        vector<string> grid(r);
        for (int i = 0; i < r; i++) cin >> grid[i];

        deque<pair<int,int>> dq;
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));

        dist[0][0] = 0;
        dq.push_front({0, 0});

        vector<int> directions = {0, 1, 0, -1, 0};

        while (!dq.empty()) {
            auto [x, y] = dq.front(); dq.pop_front();

            for (int d = 0; d < 4; d++) {
                int nx = x + directions[d], ny = y + directions[d+1];

                if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                    int cost = (grid[x][y] == grid[nx][ny]) ? 0 : 1;

                    if (dist[x][y] + cost < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + cost;
                        if (cost == 0) dq.push_front({nx, ny});
                        else dq.push_back({nx, ny});
                    }
                }
            }
        }

        cout << dist[r-1][c-1] << "\n";
    }
    return 0;
}
