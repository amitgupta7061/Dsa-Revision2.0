#include <bits/stdc++.h>
using namespace std;

struct MaxFlow {
    struct Edge {int to;int cap;int flow;int rev; };

    vector<vector<Edge>> adj;

    MaxFlow(int n) {
        adj.assign(n, vector<Edge>());
    }

    void add_edge(int from, int to, int cap) {
        adj[from].push_back({to, cap, 0, (int)adj[to].size()});
        adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1});
    }

    int bfs(int s, int t, vector<int>& parent, vector<int>& parent_edge) {
        fill(parent.begin(), parent.end(), -1);
        fill(parent_edge.begin(), parent_edge.end(), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, 1e9});

        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int i = 0; i < adj[cur].size(); i++) {
                Edge& e = adj[cur][i];
                if (parent[e.to] == -1 && e.cap - e.flow > 0) {
                    parent[e.to] = cur;
                    parent_edge[e.to] = i;
                    int new_flow = min(flow, e.cap - e.flow);
                    if (e.to == t)
                        return new_flow;
                    q.push({e.to, new_flow});
                }
            }
        }
        return 0;
    }

    int karp(int s, int t) {
        int flow = 0;
        vector<int> parent(adj.size());
        vector<int> parent_edge(adj.size());
        int new_flow;

        while ((new_flow = bfs(s, t, parent, parent_edge))) {
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int p = parent[cur];
                int idx = parent_edge[cur];
                adj[p][idx].flow += new_flow;
                adj[cur][adj[p][idx].rev].flow -= new_flow;
                cur = p;
            }
        }
        return flow;
    }
};

int crabGraphs(int n, int t, vector<vector<int>> graph) {
    MaxFlow mf(2 * n + 2);
    int s = 0;
    int d = 2 * n + 1;
    for (int i = 1; i <= n; i++) {
        mf.add_edge(s, i, t);
        mf.add_edge(i + n, d, 1);
    }
    for (const auto& edge : graph) {
        int u = edge[0];
        int v = edge[1];
        mf.add_edge(u, v + n, 1);
        mf.add_edge(v, u + n, 1);
    }
    return mf.karp(s, d);
}

int main() {

    return 0;
}