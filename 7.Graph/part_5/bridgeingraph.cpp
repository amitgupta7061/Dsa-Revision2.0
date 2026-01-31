#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto it : connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> lowtime(n, 0), discover(n, 0);
        vector<vector<int>> result;

        int currtime = 0;

        function<void(int, int)> f = [&](int node, int parent){
            lowtime[node] = discover[node] = ++currtime;

            for(int neigh : graph[node]){
                if(neigh == parent) continue;
                if(!discover[neigh]){
                    f(neigh, node);
                    lowtime[node] = min(lowtime[node], lowtime[neigh]);

                    if(lowtime[neigh] > discover[node]){
                        result.push_back({node, neigh});
                    }
                } else {
                    lowtime[node] = min(lowtime[node], lowtime[neigh]);
                }
            }
        };

        f(0, -1);
        return result;
    }
};

int main() {

    return 0;
}