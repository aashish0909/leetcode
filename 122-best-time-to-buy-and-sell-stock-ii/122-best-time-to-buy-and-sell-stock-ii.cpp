class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
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
};