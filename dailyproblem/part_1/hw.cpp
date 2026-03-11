#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int clumsy(int n) {
    vector<int> st;
    st.push_back(n);
    int op = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (op == 0) st.back() *= i;
        else if (op == 1) st.back() /= i;
        else if (op == 2) st.push_back(i);
        else st.push_back(-i);
        op = (op + 1) % 4;
    }
    int res = 0;
    for (int x : st) res += x;
    return res;
}

vector<int> grayCode(int A) {
    vector<int> res;
    int size = 1 << A;
    for (int i = 0; i < size; i++) {
        res.push_back(i ^ (i >> 1));
    }
    return res;
}

double myPow(double x, int n) {
    long long p = n;
    if (p < 0) {
        x = 1 / x;
        p = -p;
    }
    double res = 1;
    while (p) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    int res = 10, cur = 9, available = 9;
    for (int i = 2; i <= n && available > 0; i++) {
        cur *= available;
        res += cur;
        available--;
    }
    return res;
}

bool dfs23(vector<int> &a, vector<bool> &used, int depth, int val) {
    if (depth == 5) return val == 23;
    for (int i = 0; i < 5; i++) {
        if (!used[i]) {
            used[i] = true;
            if (dfs23(a, used, depth + 1, val + a[i]) ||
                dfs23(a, used, depth + 1, val - a[i]) ||
                dfs23(a, used, depth + 1, val * a[i])) {
                used[i] = false;
                return true;
            }
            used[i] = false;
        }
    }
    return false;
}

bool possible23(vector<int> a) {
    vector<bool> used(5, false);
    for (int i = 0; i < 5; i++) {
        used[i] = true;
        if (dfs23(a, used, 1, a[i])) return true;
        used[i] = false;
    }
    return false;
}

int main() {
    
}


int main() {

    return 0;
}