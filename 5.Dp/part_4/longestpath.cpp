#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> dp;

    int dfs(int u) {
        if(dp[u] != -1) return dp[u];

        int ans = 0;

        for(int v : adj[u]) {
            ans = max(ans, 1 + dfs(v));
        }

        return dp[u] = ans;
    }

    int longestPath(int N) {
        int res = 0;
        for(int i = 1; i <= N; i++) {
            res = max(res, dfs(i));
        }
        return res;
    }
};

int main() {

    int N, M;
    cin >> N >> M;

    Solution sol;
    sol.adj.resize(N+1);
    sol.dp.assign(N+1, -1);

    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        sol.adj[x].push_back(y);
    }

    cout << sol.longestPath(N);

    return 0;
}
