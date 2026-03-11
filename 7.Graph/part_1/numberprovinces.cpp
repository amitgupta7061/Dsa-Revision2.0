#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, int src, vector<int> &visited){
        visited[src] = true;
        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[src][i] and !visited[i]) DFS(isConnected, i, visited); 
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0, n = isConnected.size();
        vector<int> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                cnt++; DFS(isConnected, i, visited);
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}