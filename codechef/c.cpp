#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> num1(n), num2(n);
        
        for (int i = 0; i < n; ++i) cin >> num1[i];
        for (int i = 0; i < n; ++i) cin >> num2[i];

        long long maxi = -1; 
        bool flag = true;

        for (int i = 0; i < n; ++i) {
            if (num1[i] > num2[i]) {
                flag = false;
                break;
            }
            if (num1[i] < num2[i]) {
                if (num1[i] <= maxi) {
                    flag = false;
                    break;
                }
            }
            maxi = max(maxi, num1[i]);
        }

        if (flag) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
    return 0;
}