#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canmake(vector<int> &bloom, int mid, int m, int k){
        int cnt = 0, currk = k, n = bloom.size();
        for(int it : bloom){
            if(it > mid) currk = k;
            else if (--currk == 0) {
                cnt++; currk = k;
            }
        }
        return cnt >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end()), ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canmake(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};

int main() {

    return 0;
}