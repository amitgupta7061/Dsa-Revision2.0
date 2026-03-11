#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> mp;
        int l = 0, n = s.length(), maxi = -1;
        for(int r = 0; r < n; r++){
            mp[s[r]]++;
            while(mp.size() > k) {
                mp[s[l]] == 1 ? mp.erase(s[l]) : mp[s[l]]--;
                l++;
            }
            if(mp.size() == k) maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};

int main() {

    return 0;
}