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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(!root)
            return root;
        
        if(d == 1) {
            auto new_node = new TreeNode(v);
            new_node->left = root;
            return new_node;
            
        } else if(d == 2) {
            auto nodeL = root->left;
            auto nodeR = root->right;
            
            root->left = new TreeNode(v);
            root->left->left = nodeL;
            
            root->right = new TreeNode(v);
            root->right->right = nodeR;
            
            return root;
        }
        
        addOneRow(root->left, v, d-1);
        addOneRow(root->right, v, d-1);
        
        return root;
    }
};