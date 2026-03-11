#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(string &s, int k){
        if(k < 0) return 0;
        unordered_map<char, int> mp;
        int l = 0, cnt = 0;
        for(int r = 0; r < s.length(); r++){
            mp[s[r]]++;
            while(mp.size() > k){
                mp[s[l]] == 1 ? mp.erase(s[l]) : mp[s[l]]--;
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
    int countSubstr(string& s, int k) {
        return f(s, k) - f(s, k-1);
    }
};

class Solution {
public:
    int f(string &s, int k) {
        if (k < 0) return 0;

        vector<int> freq(26, 0);
        int l = 0, cnt = 0, distinct = 0;

        for (int r = 0; r < s.size(); r++) {
            if (freq[s[r] - 'a'] == 0) distinct++;
            freq[s[r] - 'a']++;

            while (distinct > k) {
                freq[s[l] - 'a']--;
                if (freq[s[l] - 'a'] == 0) distinct--;
                l++;
            }

            cnt += r - l + 1;
        }
        return cnt;
    }

    int countSubstr(string& s, int k) {
        return f(s, k) - f(s, k - 1);
    }
};


int main() {

    return 0;
}