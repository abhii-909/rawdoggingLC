class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left_idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        int right_idx = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();

        if(left_idx == right_idx) return {-1, -1};
        return {left_idx, right_idx - 1};
    }
};