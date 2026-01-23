#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, a = 0, b = 0, c = 0, n = s.length(), cnt = 0;
        for(int r = 0; r < n; r++){
            s[r] == 'a' ? a++ : s[r] == 'b' ? b++ : c++;
            while(a and b and c){
                cnt += n - r;
                s[l] == 'a' ? a-- : s[l] == 'b' ? b-- : c--;
                l++;
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}