class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        
        // 'a' and 'b' represent the two types of fruit in our baskets.
        // Initialized to -1 to signify empty baskets.
        int a = -1;
        int b = -1;

        // 'c1' and 'c2' are the counts of fruit 'a' and 'b' in the current window.
        int c1 = 0;
        int c2 = 0;

        int ans = 0; // Stores the maximum number of fruits collected so far.
        int i = 0; // The left pointer of our sliding window.

        // The 'j' loop represents the right pointer, expanding the window.
        for (int j = 0; j < n; j++) {
            
            // Case 1: The current fruit is of type 'a'.
            if (a == arr[j]) {
                c1++;
            }
            // Case 2: The current fruit is of type 'b'.
            else if (b == arr[j]) {
                c2++;
            }
            // Case 3: The first basket is empty, so we put the new fruit type in it.
            else if (a == -1) {
                a = arr[j];
                c1++;
            }
            // Case 4: The second basket is empty, so we put the new fruit type in it.
            else if (b == -1) {
                b = arr[j];
                c2++;
            }
            // Case 5: We've encountered a third fruit type. The window is now invalid.
            else {
                // We must shrink the window from the left (by incrementing 'i') until
                // we have removed one of the existing fruit types completely.
                while (c1 > 0 && c2 > 0) {
                    if (a == arr[i]) {
                        c1--;
                    } else if (b == arr[i]) {
                        c2--;
                    }
                    i++; // Move the left pointer to the right.
                }

                // Now, one of the counts (c1 or c2) is 0. We replace that
                // fruit type with the new fruit type arr[j].
                if (c1 == 0) {
                    a = arr[j]; // The basket that held the old 'a' now holds the new fruit.
                    c1++;
                } else if (c2 == 0) {
                    b = arr[j]; // The basket that held the old 'b' now holds the new fruit.
                    c2++;
                }
            }
            
            // After each step, the window [i, j] is valid.
            // We update our answer with the size of the current window if it's larger.
            ans = max(ans, j - i + 1);
        }
        
        return ans; // Return the maximum size found.
    }
};