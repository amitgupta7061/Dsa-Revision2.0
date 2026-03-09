#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int cnt = 0;
    vector<int> s;
    for (int x : a) {
        if (!s.empty() && x == s.back() + 1) {
            s.push_back(x);
        } 
        else {
            while (!s.empty() && s.back() > x - 1) {
                s.pop_back();
            }

            if (!s.empty() && s.back() == x - 1) {
                s.push_back(x);
            } else {
                
                cnt++;
                s.clear();
                s.push_back(x);
            }
        }
    }

    cout << cnt << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}