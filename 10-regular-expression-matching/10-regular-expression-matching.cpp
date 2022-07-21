class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
        
        dp[0][0] = true;
        
        for(int i = 2; i <= m; i++) {
            if(p[i - 1] == '*' && dp[0][i - 2])
                dp[0][i] = true;
        }
        
        for(int sPos = 1; sPos < n + 1; sPos++) {
            for(int pPos = 1; pPos < m + 1; pPos++) {
                char currS = s[sPos - 1];
                char currP = p[pPos - 1];
                if(currS == currP || currP == '.')
                    dp[sPos][pPos] = dp[sPos - 1][pPos - 1];
                else if(currP == '*') {
                    if(p[pPos - 2] != currS && p[pPos - 2] != '.')
                        dp[sPos][pPos] = dp[sPos][pPos - 2];
                    else {
                        dp[sPos][pPos] = dp[sPos][pPos] || dp[sPos - 1][pPos];
                        dp[sPos][pPos] = dp[sPos][pPos] || dp[sPos - 1][pPos - 2];
                        dp[sPos][pPos] = dp[sPos][pPos] || dp[sPos][pPos - 2];
                    }
                }
            }
        }
        
        return dp[n][m];
    }
};