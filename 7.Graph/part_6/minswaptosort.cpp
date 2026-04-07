#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<pair<int, int>> &temp, int src, int &cnt, vector<int> &visited){
        visited[src] = true;
        int next = temp[src].second;

        if(!visited[next]){
            cnt++;
            f(temp, next, cnt, visited);
        }
    }
    int minSwaps(vector<int>& arr) {
        vector<pair<int, int>> temp;
        int n = arr.size();

        for(int i = 0; i < n; i++)
            temp.push_back({arr[i], i});
        
        sort(temp.begin(), temp.end());

        vector<int> visited(n, false);
        int result = 0;

        for(int i = 0; i < n; i++){
            if(visited[i] || temp[i].second == i)
                continue;
            int cnt = 0;
            f(temp, i, cnt, visited);
            result += cnt - 1;
        }

        return result;
    }
};

int main() {

    return 0;
}