#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<pair<int, int>> &temp, vector<int> &visited, int src, int &cnt){
        visited[src] = true;
        
        if(!visited[temp[src].second]){
            cnt++;
            f(temp, visited, temp[src].second, cnt);
        }
    }
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> temp;
        for(int i = 0; i < nums.size(); i++){
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());

        vector<int> visited(nums.size(), false);
        int result = 0;

        for(int i = 0; i < nums.size(); i++){
            if(visited[i] or temp[i].second == i) continue;
            int cyclecnt = 1;
            f(temp, visited, i, cyclecnt);
            result += cyclecnt-1;
        }
        return result;
    }
};

int main() {

    return 0;
}