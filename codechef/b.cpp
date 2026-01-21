#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n + 1);
        for (int i = 1; i <= n; i++) cin >> nums[i];

        int last = 0;
        for (int i = n; i >= 1; i--) {
            if (nums[i] != i) {
                last = i;
                break;
            }
        }

        if (last == 0) {
            cout << 0 << endl;
            continue;
        }

        int mini = nums[last];
        for (int j = last; j <= n; j++) mini = min(mini, nums[j]);
        cout << mini << endl;
    }
    return 0;
}