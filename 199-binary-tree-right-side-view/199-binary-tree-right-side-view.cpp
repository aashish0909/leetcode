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
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        ans.clear();
        int maxLevel = -1;
        func(root, &maxLevel, 0);
        
        return ans;
    }
    
    void func(TreeNode* root, int *maxLevel, int level) {
        if(!root) return;
        if(level > *maxLevel) {
            *maxLevel = level;
            ans.push_back(root->val);
        }
        func(root->right, &(*maxLevel), level + 1);
        func(root->left, &(*maxLevel), level + 1);
    }
};