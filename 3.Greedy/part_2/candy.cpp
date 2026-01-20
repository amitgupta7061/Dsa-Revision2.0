#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> temp(n); 
        temp[0] = 1;
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]) temp[i] = temp[i-1] + 1;
            else temp[i] = 1;
        }

        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]) temp[i] = max(temp[i], temp[i+1]+1);
        }
        return accumulate(temp.begin(), temp.end(), 0);
    }
};

int main() {

    return 0;
}