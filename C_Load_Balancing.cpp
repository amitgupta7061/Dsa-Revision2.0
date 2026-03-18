#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int &num : nums) {
        cin >> num;
    }

    int total = accumulate(nums.begin(), nums.end(), 0);
    int low = total / n;
    int high = low + 1;
    int remainder = total % n;

    sort(nums.begin(), nums.end());


    int seconds = 0;
    for(int i = 0; i < n - remainder; i++) {
        if(nums[i] > low) {
            seconds += (nums[i] - low);  
        }
    }
    for(int i = n-remainder; i < n ; i++) {
        if(nums[i] > high) {
            seconds += (nums[i] - high);  
        }
    }

    cout << seconds << endl;


    return 0;
}