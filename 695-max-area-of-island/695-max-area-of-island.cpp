class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(!visited[i][j]) {
                    ans = max(ans, dfs(grid, visited, i, j));
                }
            }
        }
        
        return ans;
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        int count = 0;
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || 
                        visited[i][j] || grid[i][j] == 0)
            return count;
        
        count++;
        visited[i][j] = 1;
        count += dfs(grid, visited, i + 1, j);
        count += dfs(grid, visited, i - 1, j);
        count += dfs(grid, visited, i, j + 1);
        count += dfs(grid, visited, i, j - 1);
        
        return count;
    }
};