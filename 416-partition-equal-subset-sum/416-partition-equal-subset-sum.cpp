class Solution {
public:
    vector<vector<int>> dpp;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
            sum += i;
        int n = nums.size();
        
        if(sum % 2) return false;
        
        vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, false));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= sum / 2; j++) {
                if(j == 0) dp[i][j] = true;
                else if(j - nums[i] >= 0)
                    dp[i][j] = dp[i + 1][j - nums[i]] || dp[i + 1][j];
                else dp[i][j] = dp[i + 1][j];
            }
        } 
        return dp[0][sum / 2];
    }
};