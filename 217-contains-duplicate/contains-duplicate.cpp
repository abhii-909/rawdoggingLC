class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto x : nums){
            if(mpp[x] >= 1){
                return true;
            }
            mpp[x]++;
        }
        return false;
    }
};