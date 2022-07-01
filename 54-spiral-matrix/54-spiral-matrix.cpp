class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        
        while(true) {
            for(int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;
            
            if(left > right || top > bottom)
                break;
            
            for(int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;
            
            if(left > right || top > bottom)
                break;
            
            for(int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
            
            if(left > right || top > bottom)
                break;
            
            for(int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
            
            if(left > right || top > bottom)
                break;
        }
        
        return ans;
    }
};