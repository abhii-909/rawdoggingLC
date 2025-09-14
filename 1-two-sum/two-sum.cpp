class Solution {
public:
    // Better solution (Hashing)
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mpp;

        for(int i = 0; i < n; i++){
            int a = nums[i];
            int more = target - a;
            if(mpp.find(more) != mpp.end()){
                return {mpp[more], i};
            }
            mpp[a] = i;
        }
        return {-1, -1};
    }
};

// TC: O(nlogn)