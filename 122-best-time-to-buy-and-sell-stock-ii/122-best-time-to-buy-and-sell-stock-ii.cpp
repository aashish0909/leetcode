class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyin = INT_MAX, profit = 0;
        for(auto & price : prices) {
            if(price > buyin) profit += price - buyin;                
            buyin = price;
        }
        return profit;
    }
};