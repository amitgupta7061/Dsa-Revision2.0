#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> Indegree(numCourses, 0);

        for(auto it : prerequisites){
            graph[it[1]].push_back(it[0]);
            Indegree[it[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(Indegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(q.size()){
            int node = q.front(); q.pop();
            cnt++;
            for(int neigh : graph[node]){
                if(--Indegree[neigh] == 0) q.push(neigh);
            }
        }
        return cnt == numCourses;
    }
};

int main() {

    return 0;
}