class Solution {
public:
    int calc(vector<int>& prices, int fee, int i, int buy, vector<vector<int>>& dp) {
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        if(buy) {
            return dp[i][buy] = max(-prices[i] + calc(prices, fee, i + 1, 0, dp), 
                       calc(prices, fee, i + 1, 1, dp));
        }
        else
            return dp[i][buy] = max(prices[i] - fee + calc(prices, fee, i + 1, 1, dp), 
                       calc(prices, fee, i + 1, 0, dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return calc(prices, fee, 0, 1, dp);
    }
};