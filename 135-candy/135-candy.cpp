class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        vector<int> candy(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
        }
        for(int i = ratings.size() - 1; i > 0; i--) {
            if(ratings[i - 1] > ratings[i])
                candy[i - 1] = max(candy[i - 1], candy[i] + 1);
        }
        
        for(auto i : candy)
            ans += i;
        
        return ans;
    }
};