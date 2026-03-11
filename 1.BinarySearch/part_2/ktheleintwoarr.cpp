#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        if (n > m) return kthElement(nums2, nums1, k);

        int low = max(0, k - m), high = min(k, n);

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) return max(l1, l2);
            else if (l1 > r2) high = cut1 - 1;
            else low = cut1 + 1;
        }
        return -1;
    }
};


int main() {

    return 0;
}