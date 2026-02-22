#include <bits/stdc++.h>
using namespace std;

int maxGoods(int n, long long p, vector<int>& price) {
    sort(price.begin(), price.end());
    vector<long long> dp(n + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + price[i - 1];
        if (i >= 2) dp[i] = min(dp[i], dp[i - 2] + price[i - 1]);
    }

    for (int i = n; i >= 0; i--) {
        if (dp[i] <= p) return i;
    }

    return 0;
}

int main() {
    int n;
    long long p;
    cin >> n >> p;

    vector<int> price(n);
    for(int &it : price) cin >> it;

    cout << maxGoods(n, p, price) << "\n";
    return 0;
}