#include <bits/stdc++.h>
using namespace std;

void f() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    bool isequal = true;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (i > 0 && nums[i] != nums[i-1]) isequal = false;
    }

    if (isequal) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < 100; ++i) {
        isequal = true;
        for(int j=1; j<n; ++j) if(nums[j] != nums[0]) isequal = false;
        if(isequal) {
            cout << "YES" << endl;
            return;
        }

        int oddcnt = 0;
        for (long long x : nums) {
            if (abs(x) % 2 != 0) oddcnt++;
        }
        if (oddcnt > 0 && oddcnt < n) {
            cout << "NO" << endl;
            return;
        }

        if (oddcnt == 0) {
            for (int i = 0; i < n; ++i) nums[i] /= 2;
        } else {
            vector<int> bits(n);
            for(int i=0; i<n; ++i) {
                bits[i] = (nums[i] >> 1) & 1;
            }

            int temp = 0, ind = 0;

            for (int i = 0; i < N - 1; ++i) {
                if (bits[i] != bits[i+1]) {
                    temp++;
                    ind = i + 1;
                }
            }
            if (temp > 1) {
                cout << "NO" << endl;
                return;
            }
            int pivot = 1; 
            if (temp == 1) pivot = ind + 1;
            
            long long V = nums[pivot - 1];
            for (int j = 0; j < n; ++j) {
                if (j < pivot - 1) nums[j] += V;
                else nums[j] -= V;
            }
        }
    }
    
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        f();
    }
    return 0;
}