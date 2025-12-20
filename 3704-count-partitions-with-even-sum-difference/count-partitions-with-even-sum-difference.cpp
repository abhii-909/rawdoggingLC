// Approach 1 : 2 pass

class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int n = nums.size();
        int total = 0;
        for(auto x : nums) total += x;

        int ans = 0;
        int leftSum = 0;
        for(int i = 0; i <= n-2; i++){
            leftSum += nums[i];
            
            int rightSum = total - leftSum;

            if((leftSum - rightSum) % 2 == 0) ans++;
        }
        return ans;
    }
};