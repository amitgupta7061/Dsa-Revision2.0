#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool caneat(vector<int> &piles, int mid, int h){
        long long cnt = 0;
        for(auto it : piles){
            cnt += ceil((double)it / mid);
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(caneat(piles, mid, h)){
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