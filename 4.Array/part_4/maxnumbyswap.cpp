#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(string &s, int k, int ind, string &maxStr) {
        if (k == 0) return;
        int n = s.length();
        char maxDigit = s[ind];

        for (int i = ind + 1; i < n; i++) {
            if (s[i] > maxDigit) maxDigit = s[i];
        }
        if (maxDigit != s[ind]) k--;
        for (int i = n - 1; i >= ind; i--) {
            if (s[i] == maxDigit) {
                swap(s[ind], s[i]);
                if (s > maxStr) maxStr = s;
                f(s, k, ind + 1, maxStr);
                swap(s[ind], s[i]);
            }
        }
    }
    
    string findMaximumNum(string& s, int k) {
        string maxStr = s;
        f(s, k, 0, maxStr);
        return maxStr;
    }
};

string findMaximumNum(string& s, int k) {
    int n = s.length();
    for(int i = 0; i < n; i++){
        int maxi = s[i], maxid = -1;
        for(int j = i + 1; j < n; j++){
            if(s[j] > maxi){
                maxi = s[j]; maxid = j;
            }
        }
        if(maxid != -1 && k){
            k--;
            swap(s[i], s[maxid]);
        }
        if(k == 0) break;
    }
    return s;
}

int main() {

    return 0;
}