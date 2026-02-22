#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXD = 201;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        nums[i] = s[0] == '?' ? -1 : stoi(s);
    }
    if (nums[0] != -1 && nums[0] != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> dp(MAXD, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        vector<long long> suffix(MAXD + 1, 0);
        for (int d = MAXD - 1; d >= 0; d--)
            suffix[d] = (suffix[d + 1] + dp[d]) % MOD;

        fill(dp.begin(), dp.end(), 0);

        if (nums[i] == -1) {
            for (int d = 1; d < MAXD; d++)
                dp[d] = suffix[d - 1];
        } else {
            int v = nums[i];
            if (v < 1 || v >= MAXD) {
                cout << 0 << endl;
                return 0;
            }
            dp[v] = suffix[v - 1];
        }
    }

    long long ans = 0;
    for (int d = 0; d < MAXD; d++)
        ans = (ans + dp[d]) % MOD;

    cout << ans << endl;
    return 0;
}
