/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> par;
        unordered_map<TreeNode*, bool> visited;
        
        dfs(root, par);
        
        queue<TreeNode*> q;
        q.push(target);
        
        vector<int> ans;
        
        while(!q.empty() && k >= 0) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto curr = q.front();
                q.pop();
                visited[curr] = 1;
                
                if(k == 0) ans.push_back(curr->val);
                if(curr->left && !visited[curr->left])
                    q.push(curr->left);
                if(curr->right && !visited[curr->right])
                    q.push(curr->right);
                if(par[curr] && !visited[par[curr]])
                    q.push(par[curr]);
            }
                
            k--;
        }
        
        return ans;
    }
    
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& par) {
        if(!root) return;
        
        if(root->left) {
            par[root->left] = root;
            dfs(root->left, par);
        }
        if(root->right) {
            par[root->right] = root;
            dfs(root->right, par);
        }
    }
};