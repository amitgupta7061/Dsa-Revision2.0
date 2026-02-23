#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    queue<pair<int,int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        q.push({x-1, y-1});
        visited[x-1][y-1] = true;
    }

    vector<int> dir = {0, 1, 0, -1, 0};
    pair<int,int> ans;

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        ans = {x, y};

        for(int i = 0; i < 4; i++) {
            int nx = x + dir[i], ny = y + dir[i+1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    cout << ans.first + 1 << " " << ans.second + 1 << "\n";
}