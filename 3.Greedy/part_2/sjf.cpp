#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        long long curr = 0, sum = 0;
        for(int i = 0; i < bt.size(); i++){
            sum += curr;
            curr += bt[i];
        }
        return sum / bt.size();
    }
};

int main() {

    return 0;
}