class Solution {
public:
    int calc(string s, int i, vector<int>& dp) {
        if(i >= s.size())
            return 1;
        
        if(dp[i] != 0)
            return dp[i];
        
        int ans = 0;
        
        if(s[i] != '0')
            ans += calc(s, i + 1, dp);
        
        if(i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
            ans += calc(s, i + 2, dp);
        
        return dp[i] = ans;
    
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
        int n = s.size();
        dp[n] = 1;
        
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] != '0')
                dp[i] += dp[i + 1];
            if(i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
                dp[i] += dp[i + 2];
        }
        
        return dp[0];
    }
};