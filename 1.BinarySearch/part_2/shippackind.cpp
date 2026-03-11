#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool cantake(vector<int> &weight, int mid, int days){
        int day = 1, currsum = 0;
        for(int it : weight){
            if(currsum + it <= mid){
                currsum += it;
            } else{
                day++;
                currsum = it;
            }
        }
        return day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low < high){
            int mid = low + (high - low) / 2;
            if(cantake(weights, mid, days)){
                high = mid;
            } else low = mid + 1;
        }
        return high;
    }
};

int main() {

    return 0;
}