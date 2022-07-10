class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        for(int i = 1; i <= nums.size(); i++) {
            missing ^= i;
            missing ^= nums[i - 1];
        }
        
        return (missing ^ 0);
    }
};