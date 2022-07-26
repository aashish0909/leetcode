class Solution {
    int calc(vector<int>& prices, bool buy, int i, int cap, vector<vector<vector<int>>>& dp) {
        if(cap == 0)
            return 0;
        if(i == prices.size())
            return 0;
        
        if(dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        
        if(buy) {
            int bought = -prices[i] + calc(prices, 0, i + 1, cap, dp);
            int nobuy = calc(prices, 1, i + 1, cap, dp);
            
            return dp[i][buy][cap] = max(bought, nobuy);
        }
        else {
            int sold = prices[i] + calc(prices, 1, i + 1, cap - 1, dp);
            int nosell = calc(prices, 0, i + 1, cap, dp);
            return dp[i][buy][cap] = max(sold, nosell);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= 2; cap++) {
                    if(buy) {
                        int bought = -prices[i] + dp[i + 1][0][cap];
                        int nobuy = dp[i + 1][1][cap];

                        dp[i][buy][cap] = max(bought, nobuy);
                    }
                    else {
                        int sold = prices[i] + dp[i + 1][1][cap - 1];
                        int nosell = dp[i + 1][0][cap];
                        dp[i][buy][cap] = max(sold, nosell);
                    }
                }
            }
        }
        
        return dp[0][1][2];
    }
};