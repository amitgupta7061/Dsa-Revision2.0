#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRoom;
        for (int i = 0; i < n; i++)
            freeRoom.push(i);

        vector<int> countUsedRoom(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> ongoing;

        for (auto& meet : meetings) {
            int start = meet[0];
            int end = meet[1];

            while (!ongoing.empty() && ongoing.top().first <= start) {
                freeRoom.push(ongoing.top().second);
                ongoing.pop();
            }

            if (!freeRoom.empty()) {
                int room = freeRoom.top();
                freeRoom.pop();

                ongoing.push({end, room});
                countUsedRoom[room]++;
            } else {
                auto [prevEnd, room] = ongoing.top();
                ongoing.pop();
                int duration = end - start;
                ongoing.push({prevEnd + duration, room});
                countUsedRoom[room]++;
            }
        }

        int maxMeeting = 0;
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (countUsedRoom[i] > maxMeeting) {
                maxMeeting = countUsedRoom[i];
                result = i;
            }
        }

        return result;
    }
};

int main() {

    return 0;
}