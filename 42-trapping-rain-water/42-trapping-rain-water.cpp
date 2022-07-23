class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int res = 0;
        
        while(left <= right) {
            if(height[left] <= height[right]) {
                if(leftMax > height[left])
                    res += leftMax - height[left];
                else leftMax = height[left];
                left++;
            }
            else {
                if(rightMax > height[right])
                    res += rightMax - height[right];
                else rightMax = height[right];
                right--;
            }
        }
        
        return res;
    }
};