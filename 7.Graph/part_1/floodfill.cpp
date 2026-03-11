#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size(), curr = image[sr][sc];
        if(curr == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<int> directions = {0, 1, 0, -1, 0};
        image[sr][sc] = color;

        while(q.size()){
            auto [r, c] = q.front(); q.pop();
            for(int d = 0; d < 4; d++){
                int nr = r + directions[d], nc = c + directions[d+1];
                if(nr < 0 or nc < 0 or nr >= m or nc >= n or image[nr][nc] != curr) continue;
                image[nr][nc] = color;
                q.push({nr, nc});
            }
        }
        return image;
    }
};

int main() {

    return 0;
}