#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> nums1(n), nums2(n);
        int sum = 0;
        for (auto &it : nums1) {
            cin >> it;
            sum += it;
        }
        for (auto &it : nums2)  cin >> it;
        
        int mini = INT_MAX; 
        for (int i = 0; i < n; i++) {
            int diff = nums1[i] - nums2[i];
            if (diff < mini) mini = diff;
        }
        
        cout << sum - mini << "\n";
    }
    
    return 0;
}