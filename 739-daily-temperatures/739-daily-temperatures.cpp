class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        
        
        for(int i = temperatures.size() - 1; i >= 0; i--) {
            int j = i + 1;
            
            while(j < temperatures.size() && temperatures[i] >= temperatures[j]) {
                if(ans[j] > 0) j = j + ans[j];
                else j = temperatures.size();
            }
            
            if(j < temperatures.size()) ans[i] = j - i;
        }
        
        return ans;
    }
};