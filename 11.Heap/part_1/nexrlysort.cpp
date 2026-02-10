#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
            if (pq.size() > k) {
                arr[i - k] = pq.top();
                pq.pop();
            }
        }
        for (int i = n - k; i < n; i++) {
            arr[i] = pq.top();
            pq.pop();
        }
    }
};

int main() {

    return 0;
}