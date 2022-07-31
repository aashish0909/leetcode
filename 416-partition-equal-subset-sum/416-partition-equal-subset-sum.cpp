class Solution {
public:
    vector<vector<int>> dpp;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
            sum += i;
        int n = nums.size();
        
        if(sum % 2) return false;
        
        vector<vector<int>> dp(n, vector<int>((sum / 2 )+ 1, -1));
        return calc(nums, sum / 2, 0, dp);
    }
    
    bool calc(vector<int>& nums, int sum, int i, vector<vector<int>>& dp) {
        if(sum == 0)
            return true;
        if(sum < 0 || i >= nums.size())
            return false;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        return dp[i][sum] = calc(nums, sum - nums[i], i + 1, dp) || calc(nums, sum, i + 1, dp);
    }
};