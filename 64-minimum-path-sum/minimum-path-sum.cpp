// ITERATIVE

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){
                //edge case
                if(i == 0 && j == 0) continue;

                if(i == 0) grid[i][j] += grid[i][j-1];
                else if(j == 0) grid[i][j] += grid[i-1][j];

                else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};

//----------------------------------------------------------------------------------------------------------------

// PURE RECURSION (TLE)

// class Solution {
// public:
//     int solve(int i, int j, vector<vector<int>>& grid) {
//         // Base case: if we reach (0,0)
//         if (i == 0 && j == 0)
//             return grid[0][0];

//         // Out of bounds (invalid)
//         if (i < 0 || j < 0)
//             return INT_MAX;

//         // Recursive relation
//         int fromTop = solve(i - 1, j, grid);
//         int fromLeft = solve(i, j - 1, grid);

//         return grid[i][j] + min(fromTop, fromLeft);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         return solve(m - 1, n - 1, grid);
//     }
// };

//--------------------------------------------------------------------------------------------------------------

// RECURSION + MEMOIZATION

// class Solution {
// public:
//     int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {

//         if (i == 0 && j == 0)
//             return grid[0][0];

//         if (i < 0 || j < 0)
//             return INT_MAX;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         int Top = solve(i - 1, j, grid, dp);
//         int Left = solve(i, j - 1, grid, dp);

//         return dp[i][j] = grid[i][j] + min(Top, Left);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         return solve(m - 1, n - 1, grid, dp);
//     }
// };

// --------------------------------------------------------------------------------------------------------

// TABULATION

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> dp(m, vector<int>(n, 0));

//         // Base case
//         dp[0][0] = grid[0][0];

//         // Fill first row
//         for (int j = 1; j < n; j++) {
//             dp[0][j] = grid[0][j] + dp[0][j - 1];
//         }

//         // Fill first column
//         for (int i = 1; i < m; i++) {
//             dp[i][0] = grid[i][0] + dp[i - 1][0];
//         }

//         // Fill the remaining grid
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }

//         return dp[m - 1][n - 1];
//     }
// };