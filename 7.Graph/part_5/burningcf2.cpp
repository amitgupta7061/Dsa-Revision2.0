#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    vector<pair<int,int>> fires(k);
    for(int i = 0; i < k; i++) {
        cin >> fires[i].first >> fires[i].second;
    }

    int bestDist = -1;
    int ansX = 1, ansY = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            int minDist = INT_MAX;

            for(int f = 0; f < k; f++) {
                int dist = abs(i - fires[f].first) + abs(j - fires[f].second);
                minDist = min(minDist, dist);
            }

            if(minDist > bestDist) {
                bestDist = minDist;
                ansX = i;
                ansY = j;
            }
        }
    }

    cout << ansX << " " << ansY << "\n";
}