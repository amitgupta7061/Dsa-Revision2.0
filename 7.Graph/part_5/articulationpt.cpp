#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> articulationPoints(int v, vector<int> adj[]) {
        vector<int> lowtime(v, 0), discover(v, 0), isArt(v, false), result;

        int currtime = 0;

        function<void(int, int)> f = [&](int node, int parent){
            lowtime[node] = discover[node] = ++currtime;
            int childcnt = 0;

            for(int neigh : adj[node]){
                if(neigh == parent) continue;
                if(!discover[neigh]){
                    childcnt++;
                    f(neigh, node);
                    lowtime[node] = min(lowtime[node], lowtime[neigh]);

                    if(parent != -1 and lowtime[neigh] >= discover[node]){
                        isArt[node] = true;
                    }
                } else {
                    lowtime[node] = min(lowtime[node], discover[neigh]);
                }
            }

            if(parent == -1 and childcnt > 1) isArt[node] = true;
        };

        for (int i = 0; i < v; i++) {
            if (!discover[i]) f(i, -1);
        }

        for (int i = 0; i < v; i++) {
            if (isArt[i]) result.push_back(i);
        }
        if (result.empty()) return {-1};
        return result;
    }
};

int main() {

    return 0;
}