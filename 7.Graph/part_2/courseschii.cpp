#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> result, indegree(numCourses, 0);

        for(auto &it : prerequisites){
            graph[it[1]].push_back(it[0]);
            indegree[it[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(q.size()){
            int node = q.front(); q.pop();
            result.push_back(node);
            for(int neigh : graph[node]){
                if(--indegree[neigh] == 0) q.push(neigh);
            }
        }
        if (result.size() != numCourses) return {};
        return result;
    }
};

int main() {

    return 0;
}