class Solution {
private:
    int findR(vector<int>& nums, int s, int e, int target){
        if(s > e) return -1;

        int mid = s + (e - s)/2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) return findR(nums, s, mid-1, target);
        return findR(nums, mid+1, e, target);
    }
public:
    int search(vector<int>& nums, int target) {
        return findR(nums, 0, nums.size()-1, target);
    }
};