#include <bits/stdc++.h>
using namespace std;

bool possible(int k, int n, const vector<int>& a, const vector<int>& b, int min_val, int max_val) {
    if (max_val - min_val < k) return false;
    long long lb = (long long)max_val - k, ub = (long long)min_val + k;
    
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if (a[i] > lb && a[i] < ub) return false;
        }
    }
    return true;
}


int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        int mini = 1e9 + 7, maxi = -1;
        bool flag = true;

        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            if (i > 0 && nums[i] < nums[i-1]) flag = false;
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        if (flag) {
            cout << -1 << "\n";
            continue;
        }

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int low = 1, high = 1000000000, ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(mid, n, nums, temp, mini, maxi)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
