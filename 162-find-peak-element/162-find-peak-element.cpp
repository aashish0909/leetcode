class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        
        int n = nums.size();
        if(nums[n - 1] > nums[n - 2])
            return n - 1;
        if(nums[0] > nums[1])
            return 0;
        
        int left = 1, right = n - 2;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            if(nums[mid] < nums[mid - 1])
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        
        return -1;
    }
};