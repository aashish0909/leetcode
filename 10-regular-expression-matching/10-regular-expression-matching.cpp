class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        dp[0][0] = true;
        
        for(int i = 2; i <= m; i++) {
            if(p[i - 1] == '*' && dp[0][i - 2])
                dp[0][i] = true;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                char currS = s[i-1];
                char currP = p[j-1];
                
                if(currS == currP || currP == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(currP == '*') {
                    if(p[j - 2] != currS && p[j - 2] != '.')
                        dp[i][j] = dp[i][j - 2];
                    else {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 1] || dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[n][m];
    }
};