#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), result = 0;
        for(int i = 0; i < n; i++){
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++){
                freq[s[j] - 'a']++;
                int maxi = 0, mini = INT_MAX;
                for(int k = 0; k < 26; k++){
                    if(freq[k] > 0){
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }
                result += maxi - mini;
            }
        }
        return result;
    }
};


int main() {

    return 0;
}