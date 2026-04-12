#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int SZ = 100005;
const int LG = 18;

vector<int> graph[SZ];
int st[SZ], en[SZ], clk;
int parent[SZ][LG];
int lvl[SZ];
int n;

void traverse(int node, int par, int depth) {
    st[node] = ++clk;
    lvl[node] = depth;
    parent[node][0] = par;

    for (int j = 1; j < LG; j++) {
        parent[node][j] = parent[parent[node][j - 1]][j - 1];
    }

    for (auto child : graph[node]) {
        if (child != par) {
            traverse(child, node, depth + 1);
        }
    }

    en[node] = clk;
}

bool checkAncestor(int u, int v) {
    return st[u] <= st[v] && en[u] >= en[v];
}

int moveTowards(int u, int v) {
    for (int j = LG - 1; j >= 0; j--) {
        if (!checkAncestor(parent[v][j], u)) {
            v = parent[v][j];
        }
    }
    return v;
}

struct Seg {
    ll total;
    ll lazy;
} segTree[4 * SZ];

void propagate(int idx, int l, int r) {
    if (segTree[idx].lazy != 0) {
        int mid = (l + r) / 2;

        segTree[2 * idx].lazy += segTree[idx].lazy;
        segTree[2 * idx].total += (ll)(mid - l + 1) * segTree[idx].lazy;

        segTree[2 * idx + 1].lazy += segTree[idx].lazy;
        segTree[2 * idx + 1].total += (ll)(r - mid) * segTree[idx].lazy;

        segTree[idx].lazy = 0;
    }
}

void rangeUpdate(int idx, int l, int r, int ql, int qr, ll val) {
    if (l > r || l > qr || r < ql) return;

    if (l >= ql && r <= qr) {
        segTree[idx].total += (ll)(r - l + 1) * val;
        segTree[idx].lazy += val;
        return;
    }

    propagate(idx, l, r);
    int mid = (l + r) / 2;

    rangeUpdate(2 * idx, l, mid, ql, qr, val);
    rangeUpdate(2 * idx + 1, mid + 1, r, ql, qr, val);

    segTree[idx].total = segTree[2 * idx].total + segTree[2 * idx + 1].total;
}

ll rangeQuery(int idx, int l, int r, int ql, int qr) {
    if (l > r || l > qr || r < ql) return 0;

    if (l >= ql && r <= qr) return segTree[idx].total;

    propagate(idx, l, r);
    int mid = (l + r) / 2;

    return rangeQuery(2 * idx, l, mid, ql, qr) +
           rangeQuery(2 * idx + 1, mid + 1, r, ql, qr);
}

ll fastPow(ll base, ll exp) {
    ll ans = 1;
    while (exp > 0) {
        if (exp & 1) ans *= base;
        base *= base;
        exp >>= 1;
    }
    return ans;
}

int main() {

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    traverse(1, 1, 0);

    int q;
    cin >> q;

    while (q--) {
        char op;
        cin >> op;

        if (op == 'U') {
            int root, target;
            ll a, b;
            cin >> root >> target >> a >> b;

            ll val = fastPow(a, b) + fastPow(a + 1, b) + fastPow(b + 1, a);

            if (root == target) {
                rangeUpdate(1, 1, n, 1, n, val);
            }
            else if (!checkAncestor(target, root)) {
                rangeUpdate(1, 1, n, st[target], en[target], val);
            }
            else {
                int nxt = moveTowards(target, root);
                rangeUpdate(1, 1, n, 1, n, val);
                rangeUpdate(1, 1, n, st[nxt], en[nxt], -val);
            }
        }
        else {
            int root, target;
            ll mod;
            cin >> root >> target >> mod;

            ll ans = 0;

            if (root == target) {
                ans = rangeQuery(1, 1, n, 1, n);
            }
            else if (!checkAncestor(target, root)) {
                ans = rangeQuery(1, 1, n, st[target], en[target]);
            }
            else {
                int nxt = moveTowards(target, root);
                ans = rangeQuery(1, 1, n, 1, n) -
                      rangeQuery(1, 1, n, st[nxt], en[nxt]);
            }

            cout << (long long)(ans % mod) << "\n";
        }
    }

    return 0;
}