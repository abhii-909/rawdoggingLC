// // Memoization

// class Solution {
// public:
//     int solve(int i, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {
//         if (i == prices.size()) return 0;

//         if (dp[i][canBuy] != -1) return dp[i][canBuy];

//         if (canBuy == 0) { // buy = 0
//             return dp[i][0] = max(
//                 -prices[i] + solve(i + 1, 1, prices, dp),
//                 solve(i + 1, 0, prices, dp)
//             );
//         } 
//         else { // sell = 1
//             return dp[i][1] = max(
//                 prices[i] + solve(i + 1, 0, prices, dp),
//                 solve(i + 1, 1, prices, dp)
//             );
//         }
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2, -1));

//         return solve(0, 0, prices, dp);
//     }
// };

// ____________________________________________________________________________________________________________

// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[n - 1][0] = 0;
        dp[n - 1][1] = prices[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            // buy
            dp[i][0] = max(
                -prices[i] + dp[i + 1][1],
                dp[i + 1][0]
            );

            // sell
            dp[i][1] = max(
                prices[i] + dp[i + 1][0],
                dp[i + 1][1]
            );
        }
        return dp[0][0];
    }
};
