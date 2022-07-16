class Solution {
public:
    int mod = 1e9 + 7;
    int calc(vector<vector<vector<int>>>& dp, int m, int n, int maxMove, int i, int j, int moves) {
        if(i >= m || j >= n || i < 0 || j < 0)
            return 1;
        if(moves == maxMove) return 0;
        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];
        int ans = 0;
        ans = (ans + calc(dp, m, n, maxMove, i + 1, j, moves + 1)) % mod;
        ans = (ans + calc(dp, m, n, maxMove, i - 1, j, moves + 1)) % mod;
        ans = (ans + calc(dp, m, n, maxMove, i, j + 1, moves + 1)) % mod;
        ans = (ans + calc(dp, m, n, maxMove, i, j - 1, moves + 1)) % mod;
        
        return dp[i][j][moves] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1,                                                                     vector<int>(maxMove + 1, -1)));
        return calc(dp, m, n, maxMove, startRow, startColumn, 0);
    }
};