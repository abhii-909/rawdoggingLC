class Solution {
public:
    int minDistance(string word1, string word2) {
        string k = word1, s = word2;
        int n = s.size(), m = k.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= m; j++){

                if(s[i-1] == k[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return (n + m - 2*dp[n][m]);
    }
};