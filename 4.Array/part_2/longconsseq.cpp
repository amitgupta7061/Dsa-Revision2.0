#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        int result = 0;
        for(auto it : set){
            if(set.find(it - 1) == set.end()){
                int currNum = it, currStrick = 1;
                while(set.count(currNum + 1)){
                    currStrick++; currNum++;
                }
                result = max(result, currStrick);
            } 
        }
        return result;
    }
};

int main() {

    return 0;
}