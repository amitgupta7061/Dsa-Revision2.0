#include <bits/stdc++.h>
using namespace std;


class Fancy {
private:
    long long MOD = 1e9 + 7;
    vector<long long> nums;
    long long mul, add;

    long long modInverse(long long x) {
        long long power = MOD - 2;
        long long result = 1;

        while(power) {
            if(power % 2) result = (result * x) % MOD;
            x = (x * x) % MOD;
            power /= 2;
        }

        return result;
    }

public:
    Fancy() {
        mul = 1;
        add = 0;
    }
    
    void append(int val) {
        long long base = (val - add + MOD) % MOD;
        base = (base * modInverse(mul)) % MOD;
        nums.push_back(base);
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= nums.size()) return -1;
        return (nums[idx] * mul + add) % MOD;
    }
};

int main() {

    return 0;
}