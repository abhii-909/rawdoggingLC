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

        // dp[i][flag]
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            // flag = 0
            dp[i][0] = max(
                -prices[i] + dp[i + 1][1],  // buy
                dp[i + 1][0]                // skip
            );

            // flag = 1
            dp[i][1] = max(
                prices[i] + dp[i + 1][0],   // sell
                dp[i + 1][1]                // skip
            );
        }

        return dp[0][0];
    }
};
