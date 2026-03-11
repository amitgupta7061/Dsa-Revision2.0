#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> meet;
        for(int i = 0; i < start.size(); i++){
            meet.push_back({start[i], end[i]});
        }
        sort(meet.begin(), meet.end(), [&](pair<int, int> &a, pair<int, int> &b){
            return a.second < b.second;
        });
        int cnt = 1, lasttime = meet[0].second;
        for(int i = 1; i < meet.size(); i++){
            if(lasttime < meet[i].first){
                cnt++; lasttime = meet[i].second;
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}