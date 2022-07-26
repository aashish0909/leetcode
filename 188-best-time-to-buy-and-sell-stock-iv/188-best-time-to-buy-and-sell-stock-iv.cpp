class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {        
        int n = prices.size();
        
        if(k >= n / 2) {
            int ans = 0;
            int i = 0;
            while(i < n) {
                int buy = 0, sell = 0;
                while(i + 1 < n && prices[i + 1] <= prices[i])
                    ++i;
                buy = prices[i];
                while(i + 1 < n && prices[i + 1] > prices[i])
                    ++i;
                sell = prices[i];

                ans += sell - buy;
                i++;
            }

            return ans;
        }
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= k; cap++) {
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
        
        return dp[0][1][k];
    }
};