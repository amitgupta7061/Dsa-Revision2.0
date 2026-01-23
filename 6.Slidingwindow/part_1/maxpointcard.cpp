#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minsumsubarrayofk(vector<int> &cardpoints, int k){
        int n = cardpoints.size();
        if(n < k) return 0;
        int l = 0, r = 0, currsum = 0;
        while(r < k) currsum += cardpoints[r++];
        int mini = currsum;
        while(r < n){
            currsum += cardpoints[r++];
            currsum -= cardpoints[l++];
            mini = min(mini, currsum);
        }
        return mini;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int totalpt = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        return totalpt - minsumsubarrayofk(cardPoints, cardPoints.size()-k);
    }
};

int main() {

    return 0;
}