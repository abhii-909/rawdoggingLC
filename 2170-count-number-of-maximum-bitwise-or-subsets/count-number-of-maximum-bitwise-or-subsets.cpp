class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // Step 1: Find the maximum possible OR value
        // This is achieved by doing OR of all elements
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }
        
        // Step 2: Count subsets that achieve this maximum OR
        int count = 0;
        backtrack(nums, 0, 0, maxOr, count);
        
        return count;
    }
    
private:
    void backtrack(vector<int>& nums, int index, int currentOr, int targetOr, int& count) {
        // Base case: we've considered all elements
        if (index == nums.size()) {
            // If current subset's OR equals target, increment count
            if (currentOr == targetOr) {
                count++;
            }
            return;
        }
        
        // Choice 1: Include current element in subset
        // Update OR with current element and move to next
        backtrack(nums, index + 1, currentOr | nums[index], targetOr, count);
        
        // Choice 2: Skip current element (don't include in subset)
        // Keep OR same and move to next element
        backtrack(nums, index + 1, currentOr, targetOr, count);
    }
};