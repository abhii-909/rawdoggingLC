class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int o = 0, e = 0, res = 1;

        int parity = nums[0] % 2;

        for(int i = 0; i < nums.size(); i++){
            if(parity % 2 != nums[i] % 2){
                res++;
                parity ^= 1;
            }
            if(nums[i] % 2 == 1) o++;
            else e++;
        }
        return max(res, max(o, e));
    }
};