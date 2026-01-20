#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0) return 0;
        int i = 0, sign = 1, n = s.length();
        while(i < n and s[i] == ' ') i++;
        long ans = 0;
        if(s[i] == '+') i++;
        else if(s[i] == '-') {
            sign = -1; i++;
        }

        while(i < n){
            if(s[i] == ' ' or !isdigit(s[i])) break;
            ans = ans * 10 + s[i] - '0';
            if(sign == -1 and -1*ans < INT_MIN) return INT_MIN;
            if(sign == 1 and ans > INT_MAX) return INT_MAX;
            i++;
        }
        return (int)(sign*ans);
    }
};

int main() {

    return 0;
}