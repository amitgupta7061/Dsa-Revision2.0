#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int cnt = 0;

    for(int i = 0; i < n; i++){
        int lft = abs((s[i] - '0') - (t[i] - '0'));
        cnt += min(lft, 10-lft);
    }

    cout<<cnt;
    return 0;
}