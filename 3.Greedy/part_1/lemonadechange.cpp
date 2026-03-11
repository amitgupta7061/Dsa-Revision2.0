#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivecnt = 0, tencnt = 0;
        for(int num : bills){
            if (num == 5) fivecnt++;
            else if(num == 10){
                if(!fivecnt) return false;
                fivecnt--; tencnt++;
            } else{
                if(fivecnt and tencnt){
                    fivecnt--; tencnt--;
                }
                else if(fivecnt >= 3) fivecnt -= 3;
                else return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}