class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int find = target - nums[i];
            if(mp.find(find) != mp.end()) {
                vector<int> ans = {i, mp[find]};
                return ans;
            }
            
            mp[nums[i]] = i;
        }
        
        return {};
    }
};