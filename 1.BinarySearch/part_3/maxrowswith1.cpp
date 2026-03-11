#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        int maxOnes = 0, ans = -1;

        for (int i = 0; i < n; i++) {
            int low = 0, high = m - 1, firstOne = m;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (mat[i][mid] == 1) {
                    firstOne = mid;
                    high = mid - 1;
                } else low = mid + 1;
            }

            int onesCount = m - firstOne;
            if (onesCount > maxOnes) {
                maxOnes = onesCount;
                ans = i;
            }
        }

        return (maxOnes == 0) ? -1 : ans;
    }
};


int main() {

    return 0;
}