#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        int l = 1, r = n;
        for (int i = n - 1; i >= 0; --i) {
            int dist = (n - 1) - i;
            
            if (dist % 2 == 0) {
                nums[i] = r;
                r--;
            } else {
                nums[i] = l;
                l++;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
}