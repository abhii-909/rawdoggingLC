class Solution {
public:
    int dp[205][20005];

    bool ispossible(int i, int sum, vector<int>& nums){
        if(sum == 0) return true;
        if(i == nums.size() || sum < 0) return false;
        
        if(dp[i][sum] != -1) return dp[i][sum];

        //take
        bool a = ispossible(i+1, sum - nums[i], nums);
        //not take
        bool b = ispossible(i+1, sum, nums);

        return dp[i][sum] = (a || b);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for(auto x : nums) sum += x;

        if(sum % 2) return false;

        memset(dp, -1, sizeof(dp));
        return ispossible(0, sum/2, nums);
    }
};