#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> ones;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') ones.push_back(i);
        }

        if (ones.empty()) {
            cout << (n + 2) / 3 << endl;
            continue;
        }

        int sum = 0, stgap = ones[0]; 
        sum += (stgap + 1) / 3;
        for (int i = 0; i < ones.size() - 1; ++i) {
            int gapsize = ones[i+1] - ones[i] - 1;
            sum += gapsize / 3;
        }
        int endgap = n - 1 - ones.back();
        sum += (endgap + 1) / 3;
        cout << ones.size() + sum << endl;
    }
    return 0;
}