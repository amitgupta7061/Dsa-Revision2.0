#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> nums(n);
        for (auto &it : nums) cin >> it;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
            pq.push(nums[i]);

            while (pq.size() > (i + 1)) {
                pq.pop();
            }
        }

        long long maxi = 0;
        while (!pq.empty()) {
            maxi += pq.top();
            pq.pop();
        }

        cout << maxi << endl;
    }
    return 0;
}