#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestUniqueSubstr(string &s) {
        vector<int> seen(26, 0);
        int l = 0, maxi = 0;
        for (int r = 0; r < s.length(); r++) {
            l = max(l, seen[s[r] - 'a']);
            seen[s[r] - 'a'] = r + 1;
            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};



int main() {

    return 0;
}