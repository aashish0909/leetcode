/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "!";
        
        string left = serialize(root->left);
        string right = serialize(root->right);
        
        return to_string(root->val) + ';' + left + ';' + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return decode(data, i);
    }
    
    TreeNode* decode(string data, int &i) {
        if(i < data.size() && data[i] == '!') {
            i += 2;
            return NULL;
        }
        else {
            int j = i;
            while(data[j] != ';')
                ++j;
            int curr = stoi(data.substr(i, j));
            i = j + 1;
            TreeNode* root = new TreeNode(curr);
            root->left = decode(data, i);
            root->right = decode(data, i);
            
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));