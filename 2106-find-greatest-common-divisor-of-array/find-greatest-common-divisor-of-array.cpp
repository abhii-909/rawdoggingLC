class Solution {
public:
    int gcd(int a, int b) {
        int ans;
        if (b == 0){
            ans = a;
        }else{
            return gcd(b, a % b);
        }
        return ans;
    }
    int findGCD(vector<int>& nums) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            minimum = min(minimum, nums[i]);
            maximum = max(maximum, nums[i]);
        }
        return gcd(minimum, maximum);
    }
};