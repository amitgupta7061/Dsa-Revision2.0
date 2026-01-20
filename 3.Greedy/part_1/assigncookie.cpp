#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int cnt = 0, i = 0, j = 0, m = g.size(), n = s.size();
        while(i < m and j < n){
            if(g[i] <= s[j]){
                cnt++; i++; j++;
            }
            else j++;
        }
        return cnt;
    }
};

int main() {

    return 0;
}