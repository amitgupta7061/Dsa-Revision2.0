#include <bits/stdc++.h>
using namespace std;

vector<long long> countOfPairs(int n, int x, int y) {
    vector<long long> result(n, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int dist = j - i;
            int shortdist = min(abs(i - x) + 1 + abs(j - y), abs(i - y) + 1 + abs(j - x));
            
            int mini = min(dist, shortdist);
            if (mini > 0) result[mini - 1] += 2;
        }
    }
    return result;
}

int main() {
    int n = 5, x = 2, y = 4;
    vector<long long> pairs = countOfPairs(n, x, y);
    for (long long count : pairs) {
        cout << count << " ";
    }
    return 0;
}