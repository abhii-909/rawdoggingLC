class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int sum, vector<int>& nums) {
        if (sum == 0) return true;
        if (i == nums.size()) return false;

        if (dp[i][sum] != -1) return dp[i][sum];

        bool notTake = solve(i + 1, sum, nums);
        bool take = false;

        if (nums[i] <= sum) {
            take = solve(i + 1, sum - nums[i], nums);
        }

        return dp[i][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        dp.assign(nums.size(), vector<int>(target + 1, -1));

        return solve(0, target, nums);
    }
};
