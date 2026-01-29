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

int main() {

    return 0;
}