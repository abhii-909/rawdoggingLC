class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());

        int a = nums[n-1];
        int b = nums[n-2];
        long long ans = 1LL*a*b*1e5;
        return ans;
    }
};