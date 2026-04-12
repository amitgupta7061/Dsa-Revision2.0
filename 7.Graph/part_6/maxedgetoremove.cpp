#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unity(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv)
            return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet dsA(n);
        DisjointSet dsB(n);
        int cnt = 0;
        for(auto &edge: edges){
            if(edge[0] == 3){
                int u = edge[1];
                int v = edge[2];
                if(dsA.findParent(u) != dsA.findParent(v)){
                    dsA.unity(u, v);
                    dsB.unity(u, v);
                }
                else
                    cnt++;
            }
        }
        for(auto &edge: edges){
            if(edge[0] == 1){
                int u = edge[1];
                int v = edge[2];
                if(dsA.findParent(u) != dsA.findParent(v))
                    dsA.unity(u, v);
                else
                    cnt++;
            }
            else if(edge[0] == 2){
                int u = edge[1];
                int v = edge[2];
                if(dsB.findParent(u) != dsB.findParent(v))
                    dsB.unity(u, v);
                else
                    cnt++;
            }
        }
        int c1 = 0;
        int c2 = 0;
        for(int i=1; i<=n; i++){
            if(dsA.parent[i] == i)
                c1++;
            if(dsB.parent[i] == i)
                c2++;
        }
        if(c1 > 1 || c2 > 1)
            return -1;
        return cnt;
    }   
};

int main() {

    return 0;
}