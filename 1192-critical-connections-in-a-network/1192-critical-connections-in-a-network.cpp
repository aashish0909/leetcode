class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<int> in(n, -1);
        vector<int> low(n, -1);
        vector<int> visited(n, 0);
        int timer = 0;
        vector<vector<int>> graph(n, vector<int>());
        
        for(auto i : connections) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(graph, visited, in, low, i, -1, timer, ans);
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& in, vector<int>& low, int &node, int par, int &timer, vector<vector<int>>& ans) {
        
        visited[node] = 1;
        in[node] = low[node] = timer++;
        
        for(auto it : graph[node]) {
            if(it == par)
                continue;
            
            if(!visited[it]) {
                dfs(graph, visited, in, low, it, node, timer, ans);
                low[node] = min(low[node], low[it]);
                if(low[it] > in[node]) {
                    vector<int> temp = {node, it};
                    cout << node << ' ' << it;
                    ans.push_back(temp);
                }
            }
            else {
                low[node] = min(low[node], in[it]);
            }
        }
    }
};