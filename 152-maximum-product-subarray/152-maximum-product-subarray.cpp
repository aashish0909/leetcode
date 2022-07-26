class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int minP = 1, maxP = 1;
        int maxProduct = nums[0];
        
        for(auto i : nums) {
            if(i < 0)
                swap(minP, maxP);
            
            minP = min(minP * i, i);
            maxP = max(maxP * i, i);
            
            maxProduct = max(maxProduct, maxP);
        }
        
        return maxProduct;
    }
};