#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(string &s, int l, int r) {
        while (l < r) swap(s[l++], s[r--]);
    }
    string reverseWords(string s) {
        int st = 0, n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                reverse(s, st, i-1);
                st = i + 1;
            }
        }
        reverse(s, st, n-1);
        return s;
    }
};

int main() {

    return 0;
}