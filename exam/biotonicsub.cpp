#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX = 300005;
long long fact[MAX], invFact[MAX];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) fact[i] = (fact[i - 1] * i) % MOD;
    invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

long long S(int k, int v) {
    if (k < 0) return 0;
    if (v == 0) return (k == 0) ? 1 : S(k - 1, 1);
    return (nCr(2 * k + v, k) - nCr(2 * k + v, k - 1) + MOD) % MOD;
}

long long Ways(int L, int v, int u) {
    if (u < 1 || u > v + L) return 0;
    if (v == 0) return (L == 0) ? (u == 0) : Ways(L - 1, 1, u);
    if (L == 0) return (u == v) ? 1 : 0;
    
    long long res = 0;
    for (int j = 0; j <= (u - 1) / 2 && j < L; ++j) {
        long long term = (nCr(u - j - 1, j) * S(L - 1 - j, v)) % MOD;
        if (j % 2 == 1) res = (res - term + MOD) % MOD;
        else res = (res + term) % MOD;
    }
    if (u >= 2 * L + v) {
        long long term2 = nCr(u - L - v - 1, L - 1);
        if (L % 2 == 1) res = (res - term2 + MOD) % MOD;
        else res = (res + term2) % MOD;
    }
    return res;
}

int main() {
    precompute();
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        nums[i] = (s == "?") ? -1 : stoi(s);
    }

    if (nums[0] != -1 && nums[0] != 0) { cout << 0 << endl; return 0; }

    long long totalWays = 1;
    int lastPos = 0, lastVal = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] != -1) {
            totalWays = (totalWays * Ways(i - lastPos, lastVal, nums[i])) % MOD;
            lastPos = i; lastVal = nums[i];
            if (totalWays == 0) break;
        }
    }

    if (totalWays != 0) {
        totalWays = (totalWays * S(n - 1 - lastPos, lastVal)) % MOD;
    }

    cout << totalWays << endl;
    return 0;
}