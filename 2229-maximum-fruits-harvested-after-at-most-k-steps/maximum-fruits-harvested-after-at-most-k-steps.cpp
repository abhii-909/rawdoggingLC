class Solution 
{
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        int n = fruits.size();

        // Step 2: Initialize pointers and variables
        int left = 0;
        int right = 0;
        int currFruits = 0;
        int maxFruits = 0;

        // Step 3: Expand the window to the right
        while (right < n) 
        {
            currFruits += fruits[right][1];

            // Step 4 and Step 5: Shrink from left if window is unreachable
            while (left <= right && !canReach(fruits, left, right, startPos, k)) 
            {
                currFruits -= fruits[left][1];
                left++; // shrink window
            }

            // Step 6: Update max fruits collected
            maxFruits = max(maxFruits, currFruits);
            
            // Step 7: Expand to next position
            right++; 
        }

        // Step 8: Return result
        return maxFruits;
    }

private:
    // Step 4 Helper: Check if the current window is reachable in k steps
    bool canReach(vector<vector<int>>& fruits, int left, int right, int startPos, int k) 
    {
        int leftPos = fruits[left][0];
        int rightPos = fruits[right][0];

        int minSteps = min(abs(startPos - leftPos) + (rightPos - leftPos),
                           abs(startPos - rightPos) + (rightPos - leftPos));

        return minSteps <= k;
    }
};