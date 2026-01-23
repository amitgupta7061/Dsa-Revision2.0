#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int search(string &pat, string &txt) {
        int m = pat.size(), n = txt.size();
        if (m > n) return 0;
        vector<int> freqPat(26, 0), freqWin(26, 0);
        for (char c : pat) freqPat[c - 'a']++;

        int count = 0, l = 0;

        for (int r = 0; r < n; r++) {
            freqWin[txt[r] - 'a']++;
            if (r - l + 1 > m) {
                freqWin[txt[l] - 'a']--;
                l++;
            }

            if (r - l + 1 == m && freqWin == freqPat) {
                count++;
            }
        }
        return count;
    }
};



int main() {

    return 0;
}