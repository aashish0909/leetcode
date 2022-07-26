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
        
        vector<vector<int>> after(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= k; cap++) {
                    if(buy) {
                        int bought = -prices[i] + after[0][cap];
                        int nobuy = after[1][cap];

                        curr[buy][cap] = max(bought, nobuy);
                    }
                    else {
                        int sold = prices[i] + after[1][cap - 1];
                        int nosell = after[0][cap];
                        curr[buy][cap] = max(sold, nosell);
                    }
                }
            }
            after = curr;
        }
        
        return after[1][k];
    }
};