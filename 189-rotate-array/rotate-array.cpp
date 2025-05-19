class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1 || k == 0) return;  // Edge case handling
        k %= n;  // Handle large k values

        // Reverse the entire array
        manualReverse(nums, 0, n - 1);
        // Reverse the first part
        manualReverse(nums, 0, k - 1);
        // Reverse the second part
        manualReverse(nums, k, n - 1);
        // Reverse the entire array
      
    }
    void manualReverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};
