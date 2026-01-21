#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (auto &it : a) cin >> it;
        for (auto &it : b) cin >> it;
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[j] < a[i]) cnt++;
            }
        }
        
        cout << cnt << endl;
    }
    
    return 0;
}