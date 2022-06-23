class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums) mp[i]++;
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i] - 1) == mp.end()) {
                int start = nums[i];
                int count = 0;
                while(mp.find(start) != mp.end()) {
                    start++;
                    count++;
                }
                
                ans = max(ans, count);
            }
        }
        
        return ans;
    }
};