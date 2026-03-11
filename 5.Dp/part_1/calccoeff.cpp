#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int permutationCoeff(int n, int k) {
        if(k > n) return 0;
        const int mod = 1e9 + 7;
        long long result = 1;
        for(int i = 0; i < k; i++){
            result = (result * (n - i)) % mod;
        }
        return result;
    }
};


int main() {

    return 0;
}