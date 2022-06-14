/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxLevel = -1;
        traverse(ans, root, 0, &maxLevel);
                 
        return ans;
    }
    
    void traverse(vector<int>& ans, TreeNode* root, 
                  int level, int *maxLevel) {
        if(!root) return;
        
        
        if(level > *maxLevel) {
            ans.push_back(root->val);
            *maxLevel = level;
        }
        
        traverse(ans, root->right, level + 1, &(*maxLevel));
        traverse(ans, root->left, level + 1, &(*maxLevel));
    }
};