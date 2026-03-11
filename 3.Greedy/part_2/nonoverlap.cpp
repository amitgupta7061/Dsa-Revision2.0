#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt = 0, lasttime = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(lasttime > intervals[i][0]){
                cnt++;
                lasttime = min(lasttime, intervals[i][1]);
            }
            else lasttime = intervals[i][1];
        }
        return cnt;
    }
};

int main() {

    return 0;
}