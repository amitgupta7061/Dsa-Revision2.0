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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet D(m*n);
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int cnt = 0, k = operators.size();
        vector<int> result(k);
        vector<int> directions = {0, 1, 0, -1, 0};

        for(int i = 0; i < k; i++){
            int r = operators[i][0], c = operators[i][1];

            if(visited[r][c]){
                result[i] = cnt; continue;
            }

            cnt++;
            visited[r][c] = true;
            for(int d = 0; d < 4; d++){
                int nr = r + directions[d], nc = c + directions[d+1];
                if(nr >= 0 and nc >= 0 and nr < n and nc < m and visited[nr][nc]){
                    int node = r + n + c, neigh = nr + n + nc;
                    if(D.findParent(node) != D.findParent(neigh)){
                        cnt--;
                        D.unity(node, neigh);
                    }
                }
            }
            result[i] = cnt;
        }

        return result;
    }
};


int main() {

    return 0;
}