class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long totalsum = 0;
        long long arrsum = 0;

        for(int i = 0; i <= n; i++){
            totalsum += i;
        }
        for(int num : nums){
            arrsum += num;
        }
        return (int)(totalsum - arrsum);
    }
};