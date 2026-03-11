#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(string &s, string &t){
        unordered_map<char, char> mp;
        for(int i = 0; i < s.length(); i++){
            if(mp.count(s[i])){
                if(mp[s[i]] != t[i]) return false;
            } else{
                mp[s[i]] = t[i];
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return f(s, t) and f(t, s);
    }
};

int main() {

    return 0;
}