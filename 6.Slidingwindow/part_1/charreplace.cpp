#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, maxfreq = 0, n = s.length(), maxi = 0;
        vector<int> freq(26, 0);
        for(int r = 0; r < n; r++){
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq, freq[s[r] - 'A']);
            if((r-l+1) - maxfreq > k){
                freq[s[l] - 'A']--; l++;
            }
            if((r-l+1) - maxfreq <= k) maxi = max(maxi, r-l+1);
        }
        return maxi;
    }
};

int main() {

    return 0;
}