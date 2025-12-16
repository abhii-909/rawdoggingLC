// BRUTE FORCE (DFS)

class Solution {
    // DFS Helper to check if a specific initial health 'k' works
    bool canSurvive(vector<vector<int>>& dungeon, vector<vector<int>>& best,
                    int m, int n, int i, int j, int currentHealth) {
        
        // Boundary check
        if (i >= m || j >= n) return false;

        // Apply room effect
        int newHealth = currentHealth + dungeon[i][j];

        // Death check: Health must be > 0
        if (newHealth <= 0) return false;

        // Pruning: If we reached this cell before with more health, stop this path
        if (newHealth <= best[i][j]) return false;
        best[i][j] = newHealth;

        // Destination reached safely
        if (i == m - 1 && j == n - 1) return true;

        // Move Right or Down
        return canSurvive(dungeon, best, m, n, i, j + 1, newHealth) ||
               canSurvive(dungeon, best, m, n, i + 1, j, newHealth);
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        int k = 1;

        // Linear search for the minimum k
        while (true) {
            vector<vector<int>> best(m, vector<int>(n, INT_MIN));
            if (canSurvive(dungeon, best, m, n, 0, 0, k)) {
                return k;
            }
            k++;
        }
        return -1; // Should not reach here
    }
};