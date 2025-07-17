class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int maxLength = 0;
        for (int val = 0; val < k; ++val) {
            vector<int> dp(k, 0);
            for (int num : nums) {
                int rem = num % k;
                int need = (val - rem + k) % k;
                int newLen = dp[need] + 1;
                dp[rem] = max(dp[rem], newLen);
                maxLength = max(maxLength, dp[rem]);
            }
        }
        return maxLength >= 2 ? maxLength : 0;
    }
};