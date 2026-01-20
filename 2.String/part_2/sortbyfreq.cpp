#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char ch : s) freq[ch]++;

        sort(s.begin(), s.end(), [&](char &a, char &b) {
            if (freq[a] == freq[b]) return a < b;
            else return freq[a] > freq[b];
        });
        return s;
    }
};

int main() {

    return 0;
}