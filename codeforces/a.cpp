#include <iostream>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int cnt = 0;
        for (int y = x + 1; y <= x + 100; ++y) {
            if (y - digitSum(y) == x) ++cnt;
        }
        cout << cnt << "\n";
    }
    return 0;
}