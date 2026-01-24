#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;

        long long total = 0, maxi = -2e18;
        for (int i = 0; i < n; ++i) {
            long long a, b, c;
            cin >> a >> b >> c;
            
            total += a * (b - 1);
            long long curr = (a * b) - c;
            if (curr > maxi)  maxi = curr;
        }

        if (total >= x) {
            cout << 0 << "\n";
        } else {
            if (maxi <= 0) {
                cout << -1 << "\n";
            } else {
                long long need = x - total;
                long long roll = (need + maxi - 1) / maxi;
                cout << roll << "\n";
            }
        }
    }
    return 0;
}