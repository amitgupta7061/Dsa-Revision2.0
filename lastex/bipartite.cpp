#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int u = q.front(); q.pop();

                    for (int v : graph[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } 
                        else if (color[v] == color[u]) {
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

    cout << sol.isBipartite(graph) << endl;

    return 0;
}