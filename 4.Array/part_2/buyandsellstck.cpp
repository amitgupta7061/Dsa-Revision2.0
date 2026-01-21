#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0, minprice = prices[0];
        for(int i = 0; i < prices.size(); i++){
            int profit = prices[i] - minprice;
            minprice = min(minprice, prices[i]);
            maxprofit = max(maxprofit, profit);
        }
        return maxprofit;
    }
};

int main() {

    return 0;
}