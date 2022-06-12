class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        vector<int> ans(nums.size());
        int j = nums.size() - 1;
        while(left <= right) {
            if(abs(nums[left]) > abs(nums[right])) {
                ans[j] = nums[left] * nums[left];
                j--;
                left++;
            }
            else {
                ans[j] = nums[right] * nums[right];
                j--;
                right--;
            }
        }
        
        return ans;
    }
};