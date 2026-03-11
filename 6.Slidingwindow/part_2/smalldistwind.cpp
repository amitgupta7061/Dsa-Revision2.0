#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubString(string& str) {
        vector<int> freq(26, 0);
        int distinct = 0;

        for (char ch : str) {
            if (freq[ch - 'a'] == 0) distinct++;
            freq[ch - 'a']++;
        }

        vector<int> freq2(26, 0);
        int l = 0, cnt = 0, mini = INT_MAX;

        for (int r = 0; r < str.size(); r++) {
            freq2[str[r] - 'a']++;

            if (freq2[str[r] - 'a'] == 1) cnt++;

            while (cnt == distinct) {
                mini = min(mini, r - l + 1);

                freq2[str[l] - 'a']--;
                if (freq2[str[l] - 'a'] == 0) cnt--;
                l++;
            }
        }

        return mini;
    }
};


int main() {

    return 0;
}