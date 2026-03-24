#include <bits/stdc++.h>
using namespace std;

// prims algo
class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<tuple<int, int>>> graph(V);

        for(auto &it : edges){
            int u = it[0], v = it[1], w = it[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;
        vector<int> visited(V, false);
        pq.emplace(0, 0);
        int sum = 0;

        while(!pq.empty()){
            auto [wt, node] = pq.top(); pq.pop();
            if(visited[node]) continue;
            visited[node] = true;
            sum += wt;

            for(auto &[neigh, nw] : graph[node])
                if(!visited[neigh]) pq.emplace(nw, neigh);
        }
        return sum;
    }
};


class Solution {
public:
    class DisjointSet{
    public:
        vector<int> parent, size;
        DisjointSet(int n){
            size.resize(n, 1);
            parent.resize(n);
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }

        int findParent(int node){
            if(node == parent[node]) 
                return node;
            return parent[node] = findParent(parent[node]);
        }

        void unity(int u, int v){
            int ulpu = findParent(u);
            int ulpv = findParent(v);

            if(ulpu == ulpv) return;

            if(size[ulpu] < size[ulpv]){
                size[ulpv] += size[ulpu];
                parent[ulpu] = ulpv;
            } else {
                size[ulpu] += size[ulpv];
                parent[ulpv] = ulpu;
            }
        }
    };
    int spanningTree(int V, vector<vector<int>>& edges) {
        DisjointSet D(V);
        int sum = 0;

        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });

        for(auto &it : edges){
            int u = it[0], v = it[1], w = it[2];

            if(D.findParent(u) != D.findParent(v)){
                sum += w;
                D.unity(u, v);
            }
        }

        return sum;
    }
};

int main() {

    return 0;
}