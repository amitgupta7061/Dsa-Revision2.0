#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> visited(n , 0);

        function<void(int)> DFS = [&](int ind){
            visited[ind] = true;
            for(int i = 0; i < n; i++){
                if(!visited[i] and (stones[i][0] == stones[ind][0] or stones[i][1] == stones[ind][1]))
                    DFS(i);
            }
        };

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]){
                DFS(i); cnt++;
            }
        }
        return n - cnt;
    }
};

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
    int removeStones(vector<vector<int>>& stones) {
        int maxirow = -1, maxicol = -1;
        for(auto it : stones){
            maxirow = max(maxirow, it[0]);
            maxicol = max(maxicol, it[1]);
        }

        DisjointSet D(maxirow+maxicol+2);
        unordered_map<int, int> stonenodes;

        for(auto it : stones){
            D.unity(it[0], it[1]+maxirow+1);
            stonenodes[it[0]]++;
            stonenodes[it[1]+maxirow+1]++;
        }

        int connectedcomp = 0;
        for(auto it : stonenodes){
            if(D.findParent(it.first) == it.first) connectedcomp++;
        }
        return stones.size() - connectedcomp;
    }
};

int main() {

    return 0;
}