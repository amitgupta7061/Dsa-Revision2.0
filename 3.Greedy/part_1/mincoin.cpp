#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(int n) {
        vector<int> choice = {1, 2, 5, 10};
        int cnt = 0;
        for(int i = 3; i >= 0; i--){
            int quat = n / choice[i];
            n -= quat * choice[i];
            cnt += quat;
            if(n <= 0) return cnt;
        }
        return -1;
    }
};

int main() {

    return 0;
}