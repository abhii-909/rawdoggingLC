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

class Solution {
public:
    vector<int> t;

    int solve(vector<int>& coins, int amount){

        if(amount == 0) return 0;   // no coins needed
        if(amount < 0) return 1e9;  // invalid case

        if(t[amount] != -1){
            return t[amount];
        }

        int ans = 1e9;

        for(int x : coins){
            ans = min(ans, 1 + solve(coins, amount - x));
        }
        return t[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {

        t.assign(amount + 1, -1);
        
        int res = solve(coins, amount);

        return res >= 1e9 ? -1 : res;
    }
};