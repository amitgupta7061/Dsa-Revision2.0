#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size(), i = 0, j = n-1;
        while(i+1 < n and arr[i] < arr[i+1]) i++;
        while(j > 0 and arr[j-1] > arr[j]) j--;
        return i > 0 and j < n-1 and i == j;
    }
};

int main() {

    return 0;
}