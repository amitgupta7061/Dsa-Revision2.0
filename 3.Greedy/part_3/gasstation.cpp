#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int totalgas = 0, totalcost = 0, start = 0, curr = 0;
        for(int i = 0; i < gas.size(); i++){
            totalgas += gas[i];
            totalcost += cost[i];
            curr += gas[i] - cost[i];
            if(curr < 0){
                curr = 0;
                start = i+1;
            }
        }
        return totalgas >= totalcost ? start : -1;
    }
};

int main() {

    return 0;
}