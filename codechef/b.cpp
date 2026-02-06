#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long b, g, x, y, n;
        cin >> b >> g >> x >> y >> n;

        if (x + y > n) {
            cout << -1 << endl;
            continue;
        }

        long long cnt = (b + g + n - 1) / n;

        if (b >= cnt * x && g >= cnt * y) {
            cout << cnt << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}