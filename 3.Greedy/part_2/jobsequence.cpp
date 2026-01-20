#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int,int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        sort(jobs.rbegin(), jobs.rend());
        int maxDay = *max_element(deadline.begin(), deadline.end());
        vector<int> slot(maxDay + 1, -1);
        int cnt = 0, sum = 0;

        for (auto &[prof, day] : jobs) {
            for (int j = day; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = prof;
                    cnt++;
                    sum += prof;
                    break;
                }
            }
        }

        return {cnt, sum};
    }
};


int main() {

    return 0;
}