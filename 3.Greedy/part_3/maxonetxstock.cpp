#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0, mini = prices[0];
        for(int i = 0; i < prices.size(); i++){
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};


int main() {

    return 0;
}