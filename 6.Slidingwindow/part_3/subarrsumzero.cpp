#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subArrayExists(vector<int>& nums) {
        unordered_set<int> st = {0};
        int currsum = 0;
        for(int i = 0; i < nums.size(); i++){
            currsum += nums[i];
            if(st.count(currsum)) return true;
            st.insert(currsum);
        }
        return false;
    }
};

int main() {

    return 0;
}