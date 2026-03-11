#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        vector<int> freq(128, 0);
        for(auto ch : t) freq[ch]++;

        int required = t.length(), l = 0, mini = INT_MAX, start = -1;
        for(int r = 0; r < s.length(); r++){
            if(freq[s[r]] > 0) required--;
            freq[s[r]]--;

            while(required == 0){
                if(r-l+1 < mini){
                    mini = r-l+1; start = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) required++;
                l++;
            }
        }
        return mini == INT_MAX ? "" : s.substr(start, mini);
    }
};


int main() {

    return 0;
}