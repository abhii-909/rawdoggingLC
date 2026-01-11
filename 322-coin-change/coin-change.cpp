//RECURSION

// class Solution {
// public:
//     int solve(vector<int>& coins, int amount){
//         if(amount == 0) return 0;   // no coins needed
//         if(amount < 0) return 1e9;  // invalid case

//         int ans = 1e9;

//         for(int x : coins){
//             ans = min(ans, 1 + solve(coins, amount - x));
//         }
//         return ans;
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         int res = solve(coins, amount);

//         return res >= 1e9 ? -1 : res;
//     }
// };

//__________________________________________________________________________

//MEMOIZATION

// class Solution {
// public:
//     vector<int> t;

//     int solve(vector<int>& coins, int amount){

//         if(amount == 0) return 0;   // no coins needed
//         if(amount < 0) return 1e9;  // invalid case

//         if(t[amount] != -1){
//             return t[amount];
//         }

//         int ans = 1e9;

//         for(int x : coins){
//             ans = min(ans, 1 + solve(coins, amount - x));
//         }
//         return t[amount] = ans;
//     }

//     int coinChange(vector<int>& coins, int amount) {

//         t.assign(amount + 1, -1);

//         int res = solve(coins, amount);

//         return res >= 1e9 ? -1 : res;
//     }
// };

//______________________________________________________________________

// TABULATION

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        //1e9 is basically infinity
        vector<vector<int>> t(n+1, vector<int>(amount + 1, 1e9));

        //base case: 0 amount ke liye 0 coins hi lagenge na null case
        //first poore col ko 0 se bhar dega ye
        for(int i = 0; i <= n; i++){
            t[i][0] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                
                if(coins[i-1] > j)
                {
                    t[i][j] = t[i-1][j];
                }else
                {
                    t[i][j] = min(t[i-1][j], 1 + t[i][j - coins[i-1]]);
                }
            }
        }
        return t[n][amount] >= 1e9 ? -1 : t[n][amount];
    }
};