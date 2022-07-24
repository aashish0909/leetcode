class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int ans = 0;
        int minEle = prices[0];
        for(int i = 1; i < n; i++) {
            ans = max(ans, prices[i] - minEle);
            minEle = min(minEle, prices[i]);
        }
        
        return ans;
    }
};