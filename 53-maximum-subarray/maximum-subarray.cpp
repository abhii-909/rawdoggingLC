class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;

        for(int val : nums){
            if(currSum < 0) currSum = 0;
            
            currSum += val;
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};