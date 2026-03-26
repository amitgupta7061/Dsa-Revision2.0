#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    vector<pair<int,int>> onetime;
    vector<pair<int,int>> twotime;

    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {

        for (auto &it : twotime) {
            if (!(it.second <= startTime || endTime <= it.first)) {
                return false;
            }
        }

        for (auto &it : onetime) {
            if (!(it.second <= startTime || endTime <= it.first)) {
                int s = max(it.first, startTime);
                int e = min(it.second, endTime);
                twotime.push_back({s, e});
            }
        }

        onetime.push_back({startTime, endTime});

        return true;
    }
};


int main() {

    return 0;
}