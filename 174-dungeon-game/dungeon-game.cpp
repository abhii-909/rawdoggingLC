class Solution {
public:
    int m, n;
    int dp[205][205];

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        // Initialize dp with INT_MAX
        for (int i = 0; i <= m; i++) {
            
            for (int j = 0; j <= n; j++) {
                dp[i][j] = INT_MAX;
            }
        }

        // Base conditions (virtual cells)
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        // Fill table bottom-up
        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = max(1, need);
            }
        }

        return dp[0][0];
    }
};
