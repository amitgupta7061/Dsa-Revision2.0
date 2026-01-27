#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
public:
    int findTarget(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                ans = mid;
                high = mid - 1;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}