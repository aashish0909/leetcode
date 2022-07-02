class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> temp;
        solve(candidates, temp, 0, target);
        
        return ans;
    }
    
    void solve(vector<int> &candidates, vector<int> &temp, int i, int target) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(i == candidates.size())
            return;
        
        solve(candidates, temp, i + 1, target);
        
        if(candidates[i] <= target) {
            temp.push_back(candidates[i]);
            solve(candidates, temp, i, target - candidates[i]);
            temp.pop_back();
        }
    }
};