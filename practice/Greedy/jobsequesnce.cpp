#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;

        int maxDay = 0;
        for(int i = 0; i < n; i++){
            jobs.push_back({profit[i], deadline[i]});
            maxDay = max(maxDay, deadline[i]);
        }

        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());

        vector<int> used(maxDay + 1, 0);

        int cnt = 0;
        int totalprofit = 0;

        for(auto &[prof, day] : jobs){
            
            for(int j = day; j > 0; j--){
                if(used[j] == 0){
                    used[j] = 1;
                    cnt++;
                    totalprofit += prof;
                    break;
                }
            }
        }

        return {cnt, totalprofit};
    }
};

int main() {

    return 0;
}