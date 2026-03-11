#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    int route = 1, best = INT_MAX;

    for(int i = 1; i <= n; i++) {
        int s, d;
        cin >> s >> d;

        while(s < t) {
            s += d;
        }

        if(s - t < best) {
            best = s - t;
            route = i;
        }
    }

    cout << route;

    return 0;
}