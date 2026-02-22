#include <bits/stdc++.h>
using namespace std;

int countSquare(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size(), total = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1 and i > 0 && j > 0) {
                matrix[i][j] = 1 + min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]});
            }
            total += matrix[i][j];
        }
    }

    return total;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    cout << countSquare(matrix);

    return 0;
}