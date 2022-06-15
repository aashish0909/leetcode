class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos = 0;
        int low = 0, high = nums.size() - 1;
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > nums[high])
                low = mid + 1;
            else high = mid;
        }
        
        pos = high;
        
        low = 0, high = nums.size() - 1;
        int n = nums.size();
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[(mid + pos) % n] == target) return (mid + pos) % n;
            else if(nums[(mid + pos) % n] < target) low = mid + 1;
            else high = mid - 1;
        }
        
        return -1;
    }
};