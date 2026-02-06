#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> nums(n);
        for(auto &it : nums) cin >> it;

        int result = 0, i = 0;

        while (i < n - 1) {
            long long mini = nums[i], maxi = nums[i];
            bool flag = false;

            for (int j = i + 1; j < n; ++j) {
                if (nums[j] - mini > k || maxi - nums[j] > k) {
                    result++;
                    i = j + 1; 
                    flag = true;
                    break;
                }
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
            }

            if (!flag)  break;
        }

        cout << result << endl;
    }
    return 0;
}