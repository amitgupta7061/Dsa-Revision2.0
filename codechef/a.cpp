#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string str;
        cin >> n >> str;

        vector<int> freq(26, 0);
        for(char ch : str) freq[tolower(ch) - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        int ans = freq[0];
        if(freq[1] > 0) ans = freq[0] + freq[1];
        cout << ans << "\n";
    }
    return 0;
}
