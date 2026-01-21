#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int> &nums) {
        int maxi = -1, smaxi = -1;
        for(int num : nums){
            if(num > maxi){
                smaxi = maxi;
                maxi = num;
            } else if(num < maxi and num > smaxi) {
                smaxi = num;
            }
        }
        return smaxi;
    }
};

int main() {

    return 0;
}