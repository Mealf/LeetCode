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
        if(d == 1) {
            TreeNode* head = new TreeNode;
            head->val = v;
            head->left = root;
            root = head;
        } else {
            dfs(root, v, d, 2);
        }
        
        return root;
    }
    
    void dfs(TreeNode* node, int v, int d, int now_d) {
        if(!node)
            return;
        
        if(d == now_d) {
            TreeNode* new_node;
            new_node = new TreeNode;
            new_node->val = v;
            new_node->left = node->left;
            node->left = new_node;

            new_node = new TreeNode;
            new_node->val = v;
            new_node->right = node->right;
            node->right = new_node;
            
            return;
        }
        dfs(node->left, v, d, now_d+1);
        dfs(node->right, v, d, now_d+1);
    }
};