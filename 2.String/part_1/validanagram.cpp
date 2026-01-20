#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> map1(26, 0);
        vector<int> map2(26, 0);

        for(auto it : s) map1[it - 'a']++;
        for(auto it : t) map2[it - 'a']++;
        return map1 == map2;
    }
};

int main() {

    return 0;
}