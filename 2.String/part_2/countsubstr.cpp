#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstring(string s) {
        int l = 0, r = 0, a = 0, b = 0, c = 0, n = s.size(), result = 0;
        while(r < n){
            s[r] == 'a' ? a++ : s[r] == 'b' ? b++ : c++;
            while(a and b and c){
                result += n - r;
                s[l] == 'a' ? a-- : s[l] == 'b' ? b-- : c--;
                l++;
            }
            r++;
        }
        return result;
    }
};

int main() {

    return 0;
}