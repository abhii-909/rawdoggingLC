//BINARY SEARCH + DP (SLOW)

class Solution {
public:
    int m, n;
    vector<vector<int>> d;

    bool canSurvive(int H) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int start = H + d[0][0];
        if (start <= 0) return false;

        dp[0][0] = start;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (dp[i][j] <= 0) continue;

                if (i + 1 < m) {
                    int nh = dp[i][j] + d[i + 1][j];
                    if (nh > 0){
                        dp[i + 1][j] = max(dp[i + 1][j], nh);
                    }
                }

                if (j + 1 < n) {
                    int nh = dp[i][j] + d[i][j + 1];

                    if (nh > 0){
                        dp[i][j + 1] = max(dp[i][j + 1], nh);
                    }
                }
            }
        }
        return dp[m - 1][n - 1] > 0;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        d = dungeon;
        m = d.size();
        n = d[0].size();

        int low = 1, high = 1e9, ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canSurvive(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
