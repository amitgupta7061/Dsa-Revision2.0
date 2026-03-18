#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ispalindrome(string s){
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.length(), cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 1; j <= n - i; j++){
                if(ispalindrome(s.substr(i, j))) cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public: 
    int f(string &s, int l, int r, int &n){
        int cnt = 0;
        while(l >= 0 && r < n && s[l] == s[r]){
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int result = 0;

        for(int i = 0; i < n; i++){
            result += f(s, i, i, n);
            result += f(s, i, i+1, n);
        }

        return result;
    }
};

int main() {

    return 0;
}