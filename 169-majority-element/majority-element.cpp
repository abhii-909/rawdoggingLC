class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt = 0, elem = -1;

        //1: find elem
        for(auto x : nums){
            if(cnt == 0) elem = x;

            if(x == elem) cnt++;
            else cnt--;
        }

        //verify elem
        cnt = 0;
        for(auto x : nums){
            if(x == elem) cnt++;
        }
        if(cnt > n/2) return elem;
        return -1;
    }
};