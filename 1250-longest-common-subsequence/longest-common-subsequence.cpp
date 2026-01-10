// Memoization

// class Solution {
// public:
//     int t[1001][1001];

//     int solve(string& a, string& b, int i, int j){
//         if(i == a.size() || j == b.size()) return 0;

//         //already calculated
//         if(t[i][j] != -1) return t[i][j];

//         //if match
//         if(a[i] == b[j]) return t[i][j] = 1 + solve(a, b, i+1, j+1);

//         //if no match
//         return t[i][j] = max(solve(a, b, i+1, j), solve(a, b, i, j+1));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         memset(t, -1, sizeof(t));

//         return solve(text1, text2, 0, 0);
//     }
// };

// ________________________________________________________________________________

//TABULATION

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // forward dp
        vector<vector<int>> t(n + 1, vector<int>(m + 1, 0));

        //fill from bottom to top
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){

                if(text1[i] == text2[j]){
                    t[i][j] = 1 + t[i+1][j+1];
                }else{
                    t[i][j] = max(t[i+1][j], t[i][j+1]);
                }
            }
        }
        return t[0][0];
    }
};