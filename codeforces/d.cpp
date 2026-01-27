#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for(auto &it : a) cin >> it;
        vector<int> b(n);
        for(auto &it : b) cin >> it;

        sort(a.begin(), a.end(), greater<long long>());

        long long maxi = 0, need = 0;
        for (int i = 0; i < n; ++i) {
            need += b[i];
            if (need > n) break;
            long long currD = a[need - 1];
            long long currS = (long long)(i + 1) * currD;
            if (currS > maxi) maxi = currS;
        }

        cout << maxi << "\n";
    }
    return 0;
}