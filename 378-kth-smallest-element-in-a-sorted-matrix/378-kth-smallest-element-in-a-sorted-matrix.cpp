class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(count(matrix, mid) >= k) {
                // cout << mid << ' ' << count(matrix, mid) << ' ';
                right = mid;
            }
            else left = mid + 1;
        }
        
        return left;
    }
    
    int count(vector<vector<int>>& matrix, int mid) {
        int count = 0;
        int j = matrix.size() - 1;
        for(int i = 0; i < matrix.size(); i++) {
            while(j >= 0 && matrix[i][j] > mid)
                j--;
            count += (j + 1);
        }
        
        return count;
    }
};