#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--){
        int n, x, k;
        cin >> n >> x >> k;

        int ans = INT_MAX;
        for(int i = 0; i <= n; i+=k){
            ans = min(ans, abs(x-i));
        }
        cout<<ans<<"\n";
    }

    return 0;
}