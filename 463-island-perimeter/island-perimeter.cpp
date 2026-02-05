class Solution {
public:
    int n, m;
    int perimeter = 0;

    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j) {

        // out of bounds OR water
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            perimeter++;
            return;
        }

        // already visited land
        if (visited[i][j]) return;

        visited[i][j] = true;

        dfs(grid, visited, i - 1, j); // up
        dfs(grid, visited, i + 1, j); // down
        dfs(grid, visited, i, j - 1); // left
        dfs(grid, visited, i, j + 1); // right
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, visited, i, j);
                    return perimeter;   // only one island
                }
            }
        }
        return perimeter;
    }
};
