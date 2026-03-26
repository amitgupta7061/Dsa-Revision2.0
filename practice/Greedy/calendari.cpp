#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    vector<pair<int, int>> intervals;

    MyCalendar() {}

    bool book(int startTime, int endTime) {
        for (auto &[a, b] : intervals) {

            if (!(b <= startTime || endTime <= a)) {
                return false;
            }
        }

        intervals.push_back({startTime, endTime});
        return true;
    }
};


int main() {

    return 0;
}