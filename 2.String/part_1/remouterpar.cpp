#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string result = "", curr = "";
        for(int i = 0; i < s.length(); i++){
            s[i] == '(' ? cnt++ : cnt--;
            curr += s[i];
            if(cnt == 0){
                curr.pop_back();
                result += curr.substr(1);
                curr = "";
            }
        }
        return result;
    }
};

int main() {

    return 0;
}