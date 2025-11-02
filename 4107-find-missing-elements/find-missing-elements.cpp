class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> ans;

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        for(int i = mini; i <= maxi; i++){
            if(set.count(i) == 0){
                ans.push_back(i);
            }
        }
        return ans;

    }
};