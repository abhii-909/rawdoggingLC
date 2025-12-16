class Solution {
    int solve(vector<vector<int>>& dungeon, vector<vector<int>>& dp, int m, int n, int i, int j) {
        
        // Base Case: Reached the destination
        if (i == m - 1 && j == n - 1){
            if(dungeon[i][j] <=0){
                return 1 + abs(dungeon[i][j]);
            }else{
                return 1;
            }
        }

        // Out of bounds check (return huge value so this path isn't chosen)
        if (i >= m || j >= n) return INT_MAX;

        // Return memoized value
        if (dp[i][j] != -1) return dp[i][j];

        // Recursive calls for Right and Down
        int right = solve(dungeon, dp, m, n, i, j + 1);
        int down = solve(dungeon, dp, m, n, i + 1, j);

        // Calculate minimum health needed to survive next step
        int minNext = min(right, down);
        
        // Calculate health needed at current step
        int need = minNext - dungeon[i][j];
        
        // Health cannot be <= 0, so at least 1 is required
        return dp[i][j] = max(1, need);
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        // Initialize DP table with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return solve(dungeon, dp, m, n, 0, 0);
    }
};