class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({0, {i, j}});
                    visited[i][j] = 1;
                }
            }
        }
        int delrow[] = {-1, 0, 0, 1};
        int delcol[] = {0, -1, 1, 0};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.second.first;
            int col = it.second.second;
            int dist = it.first;
            for (int k = 0; k < 4; k++) {
                int nrow = delrow[k] + row;
                int ncol = delcol[k] + col;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !visited[nrow][ncol] && mat[nrow][ncol] == 1) {
                    q.push({dist + 1, {nrow, ncol}});
                    visited[nrow][ncol] = 1;
                    mat[nrow][ncol] = dist + 1;
                }
            }
        }
        return mat;
    }
};
