#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for(auto &it : nums) cin >> it;
        vector<bool> occ(n + 1, false); 

        int maxi = 0;

        for (int x : nums) {
            if (x == 1) {
                occ[1] = true;
                maxi++;
            } else {
                if (occ[x - 1]) {
                    occ[x] = true;
                    maxi++;
                }
            }
        }

        cout << maxi << "\n";
    }
    return 0;
}