class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadBuy, aheadNotBuy;
        int currBuy, currNotBuy;
        
        aheadBuy = aheadNotBuy = currBuy = currNotBuy = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            currBuy = max(-prices[i] + aheadNotBuy, aheadBuy);
            currNotBuy = max(prices[i] - fee + aheadBuy, aheadNotBuy);
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        
        return currBuy;
    }
};