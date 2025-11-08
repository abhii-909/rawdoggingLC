class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());

        while (mn != 0) {
            int temp = mx % mn;
            mx = mn;
            mn = temp;
        }
        return mx;
    }
};