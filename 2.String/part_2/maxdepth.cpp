#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, maxi = 0;
        for(char ch : s){
            if(ch == '(') cnt++;
            else if(ch == ')') cnt--;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};

int main() {

    return 0;
}