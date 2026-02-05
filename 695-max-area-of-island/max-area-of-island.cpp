class Solution {
public:
    int n, m;

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area) {

        // boundary, water, or already visited
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || visited[i][j]) {
            return;
        }

        visited[i][j] = true;
        area++;

        dfs(i - 1, j, grid, visited, area); // up
        dfs(i + 1, j, grid, visited, area); // down
        dfs(i, j - 1, grid, visited, area); // left
        dfs(i, j + 1, grid, visited, area); // right
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = 0;
                    dfs(i, j, grid, visited, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};