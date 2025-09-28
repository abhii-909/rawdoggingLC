class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());         //sort + reverse

        for(int i = 0; i < nums.size()-2; i++){
            if(nums[i] < (nums[i+1] + nums[i+2])){
                int para = nums[i] + nums[i+1] + nums[i+2];
                return para;
            }
        }
        return 0;
    }
};