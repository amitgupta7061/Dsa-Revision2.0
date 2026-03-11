#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, n = s.length(), maxi = 0;
        for(int r = 0; r < n; r++){
            if(mp.count(s[r])) l = max(l, mp[s[r]] + 1);
            maxi = max(maxi, r - l + 1);
            mp[s[r]] = r;
        }
        return maxi;
    }
};

int main() {

    return 0;
}