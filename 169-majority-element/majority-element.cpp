class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq;
        int n = nums.size();

        for(auto num : nums){
            freq[num]++;
        }
        for(auto pair : freq){
            if(pair.second > n/2){
                return pair.first;
            }
        }
        return -1; 
    }
};