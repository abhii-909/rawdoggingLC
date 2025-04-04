class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        int rightIndex = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();

        if (leftIndex == rightIndex) {
            return {-1, -1};
        }
         return {leftIndex, rightIndex - 1};
    }
};