class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();

        // Out of bounds
        if (j < 0 || j >= n) return 1e9;

        // Base case
        if (i == n - 1) return matrix[i][j];

        // Return memoized value
        if (dp[i][j] != INT_MAX) return dp[i][j];

        int down = matrix[i][j] + solve(i + 1, j, matrix, dp);
        int leftDiag = matrix[i][j] + solve(i + 1, j - 1, matrix, dp);
        int rightDiag = matrix[i][j] + solve(i + 1, j + 1, matrix, dp);

        return dp[i][j] = min({down, leftDiag, rightDiag});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, matrix, dp));
        }
        return ans;
    }
};
