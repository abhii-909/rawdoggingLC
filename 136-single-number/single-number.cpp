class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for(auto value : nums){
            sum = sum ^ value;
        }
        return sum;
    }
};