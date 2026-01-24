#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;
        
        vector<int> a(n);
        int row = 0, col = 0, both = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            
            bool canrow = (a[i] >= 1 and a[i] <= h);
            bool cancol = (a[i] >= 1 and a[i] <= l);
            
            if (canrow and cancol) both++;
            else if (canrow) row++;
            else if (cancol) col++;
        }
        
        int maxi = 0;
        
        for (int rboth = 0; rboth <= both; rboth++) {
            int cboth = both - rboth;
            
            int totalr = row + rboth, totalc = col + cboth;
            maxi = max(maxi, min({totalr, totalc, n / 2}));
        }
        
        cout << maxi << "\n";
    }
    
    return 0;
}