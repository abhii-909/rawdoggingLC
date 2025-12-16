class Solution {
public:
    int m, n;
    int dp[205][205];

    int solve(int i , int j, vector<vector<int>>& dungeon){
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
        int right = solve(i, j + 1, dungeon);
        int down = solve(i + 1, j, dungeon);

        int need = min(right, down) - dungeon[i][j];
        return dp[i][j] = max(1, need);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, dungeon);
    }
};