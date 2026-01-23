#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> firstNegInt(vector<int>& nums, int k) {
        vector<int> result(nums.size() - k + 1);
        queue<int> q;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0) q.push(i);
        }
        for(int i = 0; i < nums.size()-k+1; i++){
            if(q.size() and q.front() < i) q.pop();
            if(q.size() and q.front() <= i+k-1) result[i] = nums[q.front()];
            else result[i] = 0;
        }
        return result;
    }
};

int main() {

    return 0;
}