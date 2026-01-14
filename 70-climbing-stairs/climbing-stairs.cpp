//RECURSION

// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n < 0) return 0;
//         if(n == 0) return 1;

//         int one_step = climbStairs(n-1);
//         int two_steps = climbStairs(n-2);

//         return one_step + two_steps;
//     }
// };

//____________________________________________________________________________________________

//MEMOIZATION

// class Solution {
// public:
//     vector<int> dp;

//     int solve(int n)
//     {
//         if(n < 0) return 0;
//         if(n == 0) return 1;

//         if(dp[n] != -1) return dp[n];

//         int one_step = solve(n-1);
//         int two_steps = solve(n-2);

//         return dp[n] = one_step + two_steps;
//     }

//     int climbStairs(int n) {
//         dp.assign(n+1, -1);
//         return solve(n);
//     }
// };

//_____________________________________________________________________________________________

// TABULATION

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;

        vector<int> dp(n+1);
        
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};