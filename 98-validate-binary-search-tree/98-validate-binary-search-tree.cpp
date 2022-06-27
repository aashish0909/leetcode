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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return check(root, prev);
    }
    
    bool check(TreeNode* root, TreeNode* &prev) {
        if(!root) return true;
        
        if(!check(root->left, prev)) return false;
        
        if(prev && root->val <= prev->val) return false;
        prev = root;
        
        return check(root->right, prev);
    }
};