#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<int, int>> list;
        for(int i = 0; i < val.size(); i++){
            list.push_back({val[i], wt[i]});
        }
        sort(list.begin(), list.end(), [&](pair<int, int> &a, pair<int, int> &b){
            return (a.first*1.0) / (a.second*1.0) > (b.first*1.0) / (b.second*1.0);
        });
        double result = 0.0;
        for(auto [value, weight] : list){
            if(weight <= capacity){
                result += value * 1.0;
                capacity -= weight;
            } else {
                result += ((value*1.0) / (weight*1.0)) * capacity;
                break;
            }
        }
        return result;
    }
};


int main() {

    return 0;
}