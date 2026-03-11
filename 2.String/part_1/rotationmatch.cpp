#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        s  = s + s;
        for(int i = 0; i < s.size()-goal.size(); i++){
            if(s.substr(i, goal.size()) == goal) return true;
        }
        return false; 
    }
};

int main() {

    return 0;
}