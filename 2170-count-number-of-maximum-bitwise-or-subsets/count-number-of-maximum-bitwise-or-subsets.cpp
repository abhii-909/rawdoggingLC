class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }

        int count = 0;
        backtrack(nums, 0, 0, maxOr, count);
        return count;
    }
    
private:
    void backtrack(vector<int>& nums, int index, int currentOr, int targetOr, int& count) {
        if (index == nums.size()) {
            if (currentOr == targetOr) {
                count++;
            }
            return;
        }
        backtrack(nums, index + 1, currentOr | nums[index], targetOr, count);
        backtrack(nums, index + 1, currentOr, targetOr, count);
    }
};