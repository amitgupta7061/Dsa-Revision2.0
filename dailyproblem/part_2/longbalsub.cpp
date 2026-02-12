#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_map<int, int> visited;
        int n = nums.size(), maxi = 0;
        for(int i = 0; i < n; i++){
            unordered_set<int> even, odd;
            for(int j = i; j < n; j++){
                if(nums[j] % 2 == 0) even.insert(nums[j]);
                else odd.insert(nums[j]);
                if(even.size() == odd.size()) maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};

int main() {

    return 0;
}