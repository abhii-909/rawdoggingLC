class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long currSum = 0;
        long long maxSum = LONG_MIN;

        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];

            if(currSum > maxSum){
                maxSum = currSum;
            }

            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};