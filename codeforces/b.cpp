#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> nums1(n), nums2(n);
        for (auto &it : nums1) cin >> it;
        for (auto &it : nums2) cin >> it;

        vector<int> temp;
        if (n > 0) {
            temp.push_back(nums2[0]);
            for (int i = 1; i < n; ++i) {
                if (nums2[i] != nums2[i - 1]) temp.push_back(nums2[i]);
            }
        }
        bool flag = false;

        vector<int> freq(n + 1, 0);
        for (int x : temp) {
            if (++freq[x] > 1) {
                cout << "NO" << endl;
                flag = true;
                break;
            }
        }
        if (flag) continue;

        int ptr = 0;
        for (int i = 0; i < n && ptr < temp.size(); ++i) {
            if (nums1[i] == temp[ptr]) ptr++;
        }

        if (ptr == temp.size()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}