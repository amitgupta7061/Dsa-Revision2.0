#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    while(cin >> n){
        vector<long long> nums(n+1);
        for(int i = 1; i <= n; i++) cin >> nums[i];

        long long sum = 0;
        for(int i = (n/2)+1; i <= n; i++){
            sum += nums[i];
        }
        cout<<sum<<"\n";
    }

    return 0;
}