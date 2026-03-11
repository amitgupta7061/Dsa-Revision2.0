#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s = "";
        for(int i=0;i<min(strs[0].size(),strs[strs.size()-1].size());i++){
            if(strs[0][i]==strs[strs.size()-1][i]) s += strs[0][i];
            else return s;
        }
        return s;
    }
};

int main() {

    return 0;
}