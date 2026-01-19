#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPossible(vector<int> &stalls, int k, int dist){
        int cnt = 1, last = stalls[0];
        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i] - last >= dist){
                cnt++; last = stalls[i];
            }
            if(cnt >= k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 0, high = stalls[stalls.size()-1] - stalls[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canPossible(stalls, k, mid)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};

int main() {

    return 0;
}