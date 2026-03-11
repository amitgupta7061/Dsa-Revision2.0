#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canmakegap(vector<int> &stations, double mid, int k){
        int cnt = 0;
        for(int i = 1; i < stations.size(); i++){
            double d = stations[i] - stations[i-1];
            cnt += ceil(d / mid) - 1;
        }
        return cnt <= k;
    }
    double minMaxDist(vector<int> &stations, int k) {   
        double low = 0.0, high = stations.back() - stations[0];
        while(high - low > 1e-6){
            double mid = low + (high - low) / 2.0;
            if(canmakegap(stations, mid, k)) high = mid;
            else low = mid;
        }
        return low;
    }
};

int main() {

    return 0;
}