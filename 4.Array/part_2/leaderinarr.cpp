#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> result;
        int maxi = arr.back();
        result.push_back(arr.back());
        for(int i = arr.size()-2; i >= 0; i--){
            if(arr[i] >= maxi){
                result.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {

    return 0;
}