#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unity(int u, int v){
        int ulpu = findParent(u), ulpv = findParent(v);
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

class Solution {
public:
    int spanningTree(int v, vector<vector<int>>& edges) {
        DisjointSet D(v);
        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });
        int sum = 0;
        for(auto it : edges){
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