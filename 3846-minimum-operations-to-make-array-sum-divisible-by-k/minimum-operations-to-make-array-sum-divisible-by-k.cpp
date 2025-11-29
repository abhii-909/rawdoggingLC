class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        for(int e : nums){
            sum += e;
        }
        ans = sum % k;
        return ans;
    }
};