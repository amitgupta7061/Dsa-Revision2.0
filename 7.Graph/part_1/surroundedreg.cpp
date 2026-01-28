#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        vector<int> directions = {0, 1, 0, -1, 0};

        for(int i = 0; i < n; i++){ // 1st row and last row
            if(board[0][i] == 'O') q.push({0, i});
            if(board[m-1][i] == 'O') q.push({m-1, i});
        }

        for(int i = 0; i < m; i++){ // 1st col and last col
            if(board[i][0] == 'O') q.push({i, 0});
            if(board[i][n-1] == 'O') q.push({i, n-1});
        }

        while(q.size()){
            auto [row, col] = q.front(); q.pop();
            board[row][col] = '#';
            for(int d = 0; d < 4; d++){
                int nrow = row + directions[d], ncol = col + directions[d+1];
                if(nrow < 0 or ncol < 0 or nrow >= m or ncol >= n or 
                    board[nrow][ncol] != 'O') continue;
                q.push({nrow, ncol});
            }
        }
        for(int i = 0; i< m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};

int main() {

    return 0;
}