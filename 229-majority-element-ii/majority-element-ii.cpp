class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Find potential candidates
        // Initialize candidate tracking
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        
        // Apply voting algorithm
        for (int i = 0; i < nums.size(); i++) {
            // First candidate slot empty and not equal to el2
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            } 
            // Second candidate slot empty and not equal to el1
            else if (cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1;
                el2 = nums[i];
            } 
            // Element matches first candidate
            else if (nums[i] == el1)
                cnt1++;
            // Element matches second candidate
            else if (nums[i] == el2)
                cnt2++;
            // Element matches neither - cancellation
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        // Verify candidates
        // Calculate minimum threshold
        int min = (int)(nums.size() / 3) + 1;
        
        // Count actual occurrences
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1)
                cnt1++;
            if (nums[i] == el2)
                cnt2++;
        }
        
        // Add valid candidates to result
        vector<int> ls;
        if (cnt1 >= min)
            ls.push_back(el1);
        if (cnt2 >= min)
            ls.push_back(el2);
        
        return ls;
    }
};