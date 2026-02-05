class Solution {
public:
int n, m;
int perimeter = 0;

void dfs(vector<vector<int>> &grid, int i, int j){
    // out of bounds
    if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 0){
        perimeter++;
        return;
    }

    // already visited
    if(grid[i][j] == -1) return;

    // mark visited
    grid[i][j] = -1;

    dfs(grid, i-1, j);  //up
    dfs(grid, i, j-1); //left
    dfs(grid, i+1, j); //down
    dfs(grid, i, j+1); //right
}
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                //land
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    return perimeter;
                }
            }
        }
        return perimeter;
    }
};