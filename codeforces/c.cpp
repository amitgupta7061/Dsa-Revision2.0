#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> nums1(n), nums2(n);
        for(auto &it : nums1) cin >> it;
        for(auto &it : nums2) cin >> it;

        vector<int> maxi(n), smaxi(n);
        for (int i = 0; i < n; ++i)  maxi[i] = max(nums1[i], nums2[i]);

        if (n > 0) {
            smaxi[n - 1] = maxi[n - 1];
            for (int i = n - 2; i >= 0; --i) {
                smaxi[i] = max(maxi[i], smaxi[i + 1]);
            }
        }
        vector<long long> temp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            temp[i + 1] = temp[i] + smaxi[i];
        }

        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            cout << (temp[r] - temp[l - 1]) << " ";
        }
        cout << "\n";
    }
    return 0;
}