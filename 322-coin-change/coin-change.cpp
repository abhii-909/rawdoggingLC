class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& coins, int amount) {
        // base case
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        // memo check
        if (dp[amount] != -2) return dp[amount];

        int mini = INT_MAX;

        for (int x : coins) {
            int ans = solve(coins, amount - x);
            if (ans >= 0 && ans < mini) {
                mini = 1 + ans;
            }
        }

        // store result
        dp[amount] = (mini == INT_MAX) ? -1 : mini;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, -2);
        return solve(coins, amount);
    }
};
