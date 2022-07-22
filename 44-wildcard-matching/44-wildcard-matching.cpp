class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
        
        dp[0][0] = true;
        
        for(int j = 1; j < m + 1; j++) {
            if(p[j - 1] == '*' && dp[0][j - 1])
                dp[0][j] = true;
        }
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                char currS = s[i - 1];
                char currP = p[j - 1];
                if(currS == currP || currP == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(currP == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        
        return dp[n][m];
    }
};