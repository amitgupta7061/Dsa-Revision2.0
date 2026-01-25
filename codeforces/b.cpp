#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> nums(n), postn(n + 1); 
        
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            postn[nums[i]] = i;
        }
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != n - i) {
                l = i;
                r = postn[n - i];
                break;
            }
        }
        if (l != -1) {
            reverse(nums.begin() + l, nums.begin() + r + 1);
        }
        
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
