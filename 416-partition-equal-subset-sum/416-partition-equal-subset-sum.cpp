class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums) sum += i;
        
        if(sum % 2) return false;
        
        vector<int> partition(sum / 2 + 1, false);
        partition[0] = true;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = sum / 2; j >= nums[i]; j--) {
                partition[j] = partition[j] || partition[j - nums[i]];
            }
        }
        
        return partition[sum / 2];
    }
};