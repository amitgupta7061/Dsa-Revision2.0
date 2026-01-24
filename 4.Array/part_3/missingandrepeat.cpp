#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& nums) {
        int n = nums.size();
        long long sum = (long long)n * (n + 1) / 2;
        long long squareSum = (long long)n * (n + 1) * (2LL * n + 1) / 6;
        long long gettingSum = 0, gettingSqSum = 0;
        for (int v : nums) {
            gettingSum += v;
            gettingSqSum += 1LL * v * v;
        }
        long long diff = gettingSum - sum;
        long long sqdiff = gettingSqSum - squareSum;
        long long sum_xy = sqdiff / diff;
        long long x = (diff + sum_xy) / 2;
        long long y = sum_xy - x;
        return {(int)x, (int)y};
    }
};

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size(), i = 0;
        while (i < n) {
            int correctIdx = arr[i] - 1;
            if (arr[i] != arr[correctIdx]) swap(arr[i], arr[correctIdx]);
            else i++;
        }

        int repeating = -1, missing = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                repeating = arr[i];
                missing = i + 1;
                break;
            }
        }   

        return {repeating, missing};
    }
};


class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int repeating = -1, missing = -1;

        for (int i = 0; i < arr.size(); i++) {
            int ind = abs(arr[i]) - 1;
            
            if (arr[ind] < 0) repeating = abs(arr[i]);
            else arr[ind] = -arr[ind];
        }
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        
        return {repeating, missing};
    }
};


int main() {

    return 0;
}