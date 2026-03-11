#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();

        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) {
                if (result.empty() || result.back() != nums1[i]) result.push_back(nums1[i]);
                i++; j++;
            } 
            else if (nums1[i] < nums2[j]) {
                if (result.empty() || result.back() != nums1[i]) result.push_back(nums1[i]);
                i++;
            } 
            else {
                if (result.empty() || result.back() != nums2[j]) result.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            if (result.empty() || result.back() != nums1[i]) result.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            if (result.empty() || result.back() != nums2[j]) result.push_back(nums2[j]);
            j++;
        }

        return result;
    }
};


int main() {

    return 0;
}