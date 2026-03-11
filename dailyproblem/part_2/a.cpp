#include <bits/stdc++.h>
using namespace std;

vector<int> maxiInKWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        while (dq.size() and dq.front() <= i - k) dq.pop_front();

        while (dq.size() and nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

vector<int> prevGreaterElement(vector<int>& nums) {

    stack<int> st;
    int n = nums.size();
    vector<int> result(n, -1);

    for (int i = 0; i < n; i++) {
        while (st.size() and nums[st.top()] <= nums[i]) st.pop();

        result[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return result;
}

int firstWindowValT(vector<int>& nums, int t, int d) {
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] <= t) {
            cnt++;
            if (cnt == d) return i - d + 2;
        } else cnt = 0;
    }
    return -1;
}

int minIndMaxiWindow(vector<int>& nums, int d) {
    deque<int> dq;
    int mini = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
        while (dq.size() and dq.front() <= i - d) dq.pop_front();

        while (dq.size() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);

        if (i >= d - 1)  mini = min(mini, nums[dq.front()]);
    }
    return mini;
}


int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int &it : nums) cin >> it;

    int k, t, d;
    cin >> k >> t >> d;


    vector<int> r1 = maxiInKWindow(nums, k);
    vector<int> r2 = prevGreaterElement(nums);

    for(int it : r1) cout<<it<<" ";
    cout<<"\n";

    for(int it : r2) cout<<it<<" ";
    cout<<"\n";

    cout<<firstWindowValT(r1, t, d)<<"\n";
    cout<<minIndMaxiWindow(r1, d)<<"\n";

    return 0;
}