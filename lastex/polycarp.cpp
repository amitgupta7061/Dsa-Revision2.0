#include <bits/stdc++.h>
using namespace std;

int canReachStation(int s, vector<int>& a, vector<int>& b) {
    if (a[0] == 0) return 0;
    if (a[s - 1] == 1) return 1;
    if (b[s - 1] == 1) {
        for (int i = s; i < a.size(); ++i) {
            if (a[i] == 1 && b[i] == 1) return 1;
        }
    }

    return 0;
}

int main() {
    int s = 2;
    vector<int> a = {0, 1, 1, 1, 1};
    vector<int> b = {1, 1, 1, 1, 1};

    cout << canReachStation(s, a, b) << endl;

    return 0;
}