#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size();
        int n = secondList.size();

        if(!m or !n) return {};

        vector<vector<int>> result;

        int i = 0, j = 0;
        while(i < m && j < n){
            int start = max(firstList[i][0], secondList[j][0]);
            int end   = min(firstList[i][1], secondList[j][1]);

            if(start <= end)
                result.push_back({start, end});
            if(firstList[i][1] < secondList[j][1])
                i++;
            else 
                j++;
        }

        return result;
    }
};

int main() {

    return 0;
}