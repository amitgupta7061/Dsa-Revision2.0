#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string X;
    cin >> X;

    bool dp[2] = {true, false};

    for (int k = 1; k <= n; ++k) {
        bool nextdp[2] = {false, false};
        char x = X[k - 1];

        for (int p = 0; p < 2; ++p) {
            if (!dp[p]) continue;
            char leftchar = ((p + 1) % 2 != 0) ? 'a' : 'b';
            if (x == '?' || x == leftchar) {
                nextdp[(p + 1) % 2] = true;
            }

            char rghtchar = ((n - k + 1 + p) % 2 != 0) ? 'a' : 'b';
            if (x == '?' || x == rghtchar) {
                nextdp[p] = true;
            }
        }
        dp[0] = nextdp[0];
        dp[1] = nextdp[1];
    }

    if (dp[0] || dp[1]) cout << "YES\n";
    else  cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}