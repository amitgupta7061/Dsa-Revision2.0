#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long power(long long base, int exp) {
        long long result = 1;
        while (exp--) {
            result *= base;
        }
        return result;
    }

    int NthRoot(int N, int M) {
        long long low = 1, high = M;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = power(mid, N);

            if (val == M) return mid;
            else if (val < M) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};



int main() {

    return 0;
}