class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.begin(), nums.end());
        
        for(int i = 1; i < nums.size(); i++) {
            if(i < 2) dp[i] = max(dp[i - 1], nums[i]);
            else dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        return dp.back();
    }
};