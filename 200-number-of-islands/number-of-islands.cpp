class Solution {
public:
    int n, m;

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return islands;
    }

private:
    void dfs(vector<vector<char>>& grid,
             vector<vector<bool>>& visited,
             int i, int j) {

        // boundary + water + already visited
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() 
             || grid[i][j] == '0' || visited[i][j]) {
            return;
        }

        visited[i][j] = true;

        dfs(grid, visited, i - 1, j); // up
        dfs(grid, visited, i + 1, j); // down
        dfs(grid, visited, i, j - 1); // left
        dfs(grid, visited, i, j + 1); // right
    }
};
