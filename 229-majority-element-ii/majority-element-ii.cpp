class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Phase 1: Find potential candidates
        // Step 1: Initialize candidate tracking
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        
        // Step 2 & 3: Apply voting algorithm
        for (int i = 0; i < nums.size(); i++) {
            // Rule 1: First candidate slot empty and not equal to el2
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            } 
            // Rule 2: Second candidate slot empty and not equal to el1
            else if (cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1;
                el2 = nums[i];
            } 
            // Rule 3: Element matches first candidate
            else if (nums[i] == el1)
                cnt1++;
            // Rule 4: Element matches second candidate
            else if (nums[i] == el2)
                cnt2++;
            // Rule 5: Element matches neither - cancellation
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        // Phase 2: Verify candidates
        // Step 4: Calculate minimum threshold
        int min = (int)(nums.size() / 3) + 1;
        
        // Step 5: Count actual occurrences
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1)
                cnt1++;
            if (nums[i] == el2)
                cnt2++;
        }
        
        // Step 6: Add valid candidates to result
        vector<int> ls;
        if (cnt1 >= min)
            ls.push_back(el1);
        if (cnt2 >= min)
            ls.push_back(el2);
        
        return ls;
    }
};