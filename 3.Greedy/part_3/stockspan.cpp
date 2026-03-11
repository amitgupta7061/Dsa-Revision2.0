#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        st.push(0);
        result[0] = 1;

        for(int i = 1; i < n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if(st.empty()) result[i] = i + 1;
            else result[i] = i - st.top();
            st.push(i);
        }

        return result;
    }
};


int main() {

    return 0;
}