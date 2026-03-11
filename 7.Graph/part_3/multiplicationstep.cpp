#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& nums, int start, int end) {
        const int MOD = 100000;
        vector<int> dist(MOD, -1);

        queue<int> q;
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            if (curr == end) return dist[curr];

            for (int x : nums) {
                int next = (curr * x) % MOD;
                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};


int main() {

    return 0;
}