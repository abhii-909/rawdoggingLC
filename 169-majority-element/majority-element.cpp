class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore's Voting algo
        int freq = 0, ans = 0;

        for(int val : nums){
            if(freq == 0) ans = val;
            if(ans == val) freq++;
            else freq--;
        }
        return ans;
    }
};