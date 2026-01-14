//Approach-1 (TopDown: Recur+Memo) 
//T.C : O(n*n)

class Solution {
public:
    int n;
    int t[2501][2501];

    int lis(vector<int>& nums, int prev, int curr) {
       if(curr == n) return 0;
        
        if(prev != -1 && t[prev][curr] != -1){
            return t[prev][curr];
        }
        
        int taken = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            taken = 1 + lis(nums, curr, curr+1);
        }
        int not_taken = lis(nums, prev, curr+1);
        
        if(prev != -1){
            t[prev][curr] =  max(taken, not_taken);
        }
        
        return max(taken, not_taken);
            
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        n = nums.size();
        return lis(nums, -1, 0);
    }
};