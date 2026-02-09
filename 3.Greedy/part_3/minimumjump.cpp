#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int step = 0, curr = 0, maxi = 0;
        for(int i = 0; i < arr.size()-1; i++){
            if(i > maxi) return -1;
            maxi = max(maxi, i+arr[i]);
            if(curr == i){
                if(curr == maxi) return -1;
                step++; curr = maxi;
            }
        }
        return step;
    }
};


int main() {

    return 0;
}