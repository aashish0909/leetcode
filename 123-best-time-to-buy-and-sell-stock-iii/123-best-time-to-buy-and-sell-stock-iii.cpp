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
        int buy1 = INT_MAX;
        int profit1 = INT_MIN;
        int buy2 = INT_MAX;
        int profit2 = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            buy1 = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2 = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return calc(prices, 1, 0, 2, dp);
        return profit2;
    }
};