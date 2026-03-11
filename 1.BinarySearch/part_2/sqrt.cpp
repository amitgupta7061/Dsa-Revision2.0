#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(mid*mid == x) return mid;
            else if(mid*mid < x) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        int i;
        for(i = 1; (long long)i*i < x; i++){
            long long num = (long long)i * i;
            if(i*i == x) return i;
        }
        return i-1;
    }
};

int main() {

    return 0;
}