#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(string &s, int l, int r) {
        while (l < r) swap(s[l++], s[r--]);
    }
    string reverseStr(string s, int k) {
        int cnt = 0, n = s.length(), st = 0;
        bool havetoskip = false;
        for(int i = 0; i < n; i++){
            cnt++;
            if(cnt == k){
                cnt = 0;
                if(!havetoskip) reverse(s, st, i);
                havetoskip = !havetoskip;
                st = i+1;
            }
        }

        if(cnt <= k and !havetoskip) reverse(s, st, n-1);
        return s;
    }
};

int main() {

    return 0;
}