#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int l = 0, r = 0, n = fruits.size(), maxi = 0;

        while(r < n){
            mp[fruits[r]]++;
            while(mp.size() > 2){
                mp[fruits[l]] == 1 ? mp.erase(fruits[l]) : mp[fruits[l]]--;
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};

int main() {

    return 0;
}