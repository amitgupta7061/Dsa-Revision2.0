#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(long long mid, int mountainHeight, vector<int>& workerTimes) {
        long long total = 0;
        
        for (long long time : workerTimes) {
            total += (sqrt(1 + 8.0 * mid / time) - 1) / 2;
            if (total >= mountainHeight) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long l = 1, r = 1e18;
        long long ans = r;

        while (l <= r) {
            long long mid = (l + r) / 2;
            if (isPossible(mid, mountainHeight, workerTimes)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    return 0;
}