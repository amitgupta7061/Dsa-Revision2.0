#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, int ones, int zeros, string &curr, vector<string> &result) {
        if (curr.size() == n) {
            result.push_back(curr);
            return;
        }

        curr.push_back('1');
        solve(n, ones + 1, zeros, curr, result);
        curr.pop_back();

        if (zeros < ones) {
            curr.push_back('0');
            solve(n, ones, zeros + 1, curr, result);
            curr.pop_back();
        }
    }

    vector<string> NBitBinary(int n) {
        vector<string> result;
        string curr = "";
        solve(n, 0, 0, curr, result);
        return result;
    }
};


int main() {

    return 0;
}