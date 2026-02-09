#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        return arr.back()-k - arr[0]+k;
    }
};

int main() {

    return 0;
}