#include <bits/stdc++.h>
using namespace std;


int main() {

    int n, m;
    cin >> n >> m;

    vector<bool> on(m, false);

    while(n--){
        int bulb;
        cin >> bulb;

        while(bulb--){
            int x;
            cin >> x;

            on[--x] = true;
        }
    }

    for(auto it : on){
        if(!it){
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES";

    return 0;
}