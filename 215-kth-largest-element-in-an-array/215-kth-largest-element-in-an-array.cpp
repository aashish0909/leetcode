class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k + 1;
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int idx = partition(nums, left, right);
            if(idx == k - 1)
                return nums[idx];
            else if(idx < k - 1) {
                left = idx + 1;
            }
            else right = idx - 1;
        }
        
        return -1;
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int i = (left - 1);
        int randPivot = rand() % (right - left + 1) + left;
        swap(nums[randPivot], nums[right]);
        
        for(int j = left; j < right; j++) {
            if(nums[j] < nums[right]) {
                ++i;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return (i + 1);
    }
};