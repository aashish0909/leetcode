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
        vector<int> dp(s.size(), 0);
        return calc(s, 0, dp);
    }
};