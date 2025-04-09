class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int l = 1;
        int r = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > r) {
                r = nums[i];
            }
        }   
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            for (int x : nums) {
                s += (x + mid - 1) / mid;
            }
            if (s <= threshold) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;   
    }
}