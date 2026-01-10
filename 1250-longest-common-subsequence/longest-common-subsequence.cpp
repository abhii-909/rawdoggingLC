class Solution {
public:
    int t[1001][1001];

    int solve(string& a, string& b, int i, int j){
        if(i == a.size() || j == b.size()) return 0;

        //already calculated
        if(t[i][j] != -1) return t[i][j];

        //if match
        if(a[i] == b[j]) return t[i][j] = 1 + solve(a, b, i+1, j+1);

        //if no match
        return t[i][j] = max(solve(a, b, i+1, j), solve(a, b, i, j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t, -1, sizeof(t));

        return solve(text1, text2, 0, 0);
    }
};