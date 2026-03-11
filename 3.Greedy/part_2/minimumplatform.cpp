#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int maxi = 0, curr = 0, i = 0, j = 0;
        while(i < arr.size() and j < dep.size()){
            if(arr[i] <= dep[j]){
                curr++; maxi = max(maxi, curr); i++;
            } else {
                curr--; j++;
            }
        }
        return maxi;
    }
};


int main() {

    return 0;
}