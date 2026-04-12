#include <bits/stdc++.h>
using namespace std;

void findSCC(int u, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low,
             vector<bool> &inSt, stack<int> &st, int &timer, vector<vector<int>> &allSCCs) {
    disc[u] = low[u] = ++timer;

    st.push(u);
    inSt[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {

            findSCC(v, adj, disc, low, inSt, st, timer, allSCCs);
            low[u] = min(low[u], low[v]);
        }
        else if (inSt[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (low[u] == disc[u]) {

        vector<int> scc;
        while (true) {

            int x = st.top();
            st.pop();
            inSt[x] = false;

            scc.push_back(x);

            if (x == u)
                break;
        }
        allSCCs.push_back(scc);
    }
}

vector<vector<int>> getSCCs(vector<vector<int>> &adj) {

    int n = adj.size();

    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> inSt(n, false);

    stack<int> st;
    int timer = 0;

    vector<vector<int>> allSCCs;
    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            findSCC(i, adj, disc, low, inSt, st, timer, allSCCs);
        }
    }

    return allSCCs;
}
