#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1) return s;
        int st = 0, maxi = 1;

        auto f = [&](int l, int r){
            while(l >= 0 and r < n and s[l] == s[r]){
                if(r - l + 1 > maxi){
                    maxi = r - l + 1;
                    st = l;
                }
                l--; r++;
            }
        };

        for(int i = 0; i < n; i++){
            f(i, i); // odd length
            f(i, i+1); // even length
        }
        return s.substr(st, maxi);
    }
};

int main() {

    return 0;
}