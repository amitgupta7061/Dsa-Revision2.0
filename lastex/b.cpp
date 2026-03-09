#include <bits/stdc++.h>
using namespace std;

int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
    vector<vector<int>> adj(t_nodes + 1);

    for (int i = 0; i < t_edges; i++) {
        int u = t_from[i];
        int v = t_to[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;

    function<int(int,int)> dfs = [&](int u, int parent) -> int {
        int treesize = 1;

        for (int v : adj[u]) {
            if (v == parent) continue;

            int childSize = dfs(v, u);
            if (childSize % 2 == 0) cnt++;
            else treesize += childSize;
        }

        return treesize;
    };

    dfs(1, 0);
    return cnt;
}

int main() {

    return 0;
}