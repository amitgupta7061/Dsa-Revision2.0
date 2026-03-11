#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length(), maxi = 0;

        for(int i = 0; i < n; i++) {
            vector<int> cnt(26, 0);
            for(int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;
                int freq = 0, ok = true;
                for(int k = 0; k < 26; k++) {
                    if(cnt[k] > 0) {
                        if(freq == 0) freq = cnt[k];
                        else if(cnt[k] != freq) {
                            ok = false;
                            break;
                        }
                    }
                }

                if(ok) maxi = max(maxi, j - i + 1);
            }
        }

        return maxi;
    }
};



int main() {

    return 0;
}