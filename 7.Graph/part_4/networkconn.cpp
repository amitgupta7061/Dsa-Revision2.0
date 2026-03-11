#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> size, parent;
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
        } else{
            size[ulpu] += size[ulpv];
            parent[ulpv] = ulpu;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet D(n);
        int connectedcomp = 0, extraedge = 0;

        for(auto it : connections){
            if(D.findParent(it[0]) != D.findParent(it[1])) D.unity(it[0], it[1]);
            else extraedge++;
        }
        for(int i = 0; i < n; i++) if(D.parent[i] == i) connectedcomp++;
        return connectedcomp-1 <= extraedge ? connectedcomp-1 : -1;
    }
};

int main() {

    return 0;
}