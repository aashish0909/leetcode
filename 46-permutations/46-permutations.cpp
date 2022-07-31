class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        helper(nums, 0, nums.size() - 1);
        return ans;
    }
    
    void helper(vector<int>& nums, int left, int right) {
        if(left == right) {
            ans.push_back(nums);
            return;
        }
        
        for(int i = left; i <= right; i++) {
            swap(nums[left], nums[i]);
            helper(nums, left + 1, right);
            swap(nums[left], nums[i]);
        }
    }
};