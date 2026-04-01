#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += h[i];
    }

    int minSum = sum;
    int index = 0;

    for (int i = k; i < n; i++) {
        sum += h[i];   
        sum -= h[i - k];

        if (sum < minSum) {
            minSum = sum;
            index = i - k + 1;
        }
    }

    cout << index + 1 << endl;

    return 0;
}