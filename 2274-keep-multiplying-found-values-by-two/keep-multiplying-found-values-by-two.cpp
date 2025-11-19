class Solution {
public:
    int findFinalValue(vector<int>& nums, int a) {
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == a){
                a = a*2;
                i = 0;
            }else{
                i++;
            }
        }
        return a;
    }
};