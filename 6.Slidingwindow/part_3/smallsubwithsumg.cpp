#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int l = 0, mini = INT_MAX, currsum = 0;
        for(int r = 0; r < arr.size(); r++){
            currsum += arr[r];
            while(currsum > x){
                mini = min(mini, r - l + 1);
                currsum -= arr[l];
                l++;
            }
        }
        return mini;
    }
};

int main() {

    return 0;
}