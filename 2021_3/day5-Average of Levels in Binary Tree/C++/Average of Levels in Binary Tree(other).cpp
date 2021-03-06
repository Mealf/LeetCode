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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == nullptr)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        double sum=0;
        int count=0;
        TreeNode *node;
        
        while(!q.empty()) {
            for(int i=0, n=q.size();i<n;i++) {
                node = q.front();
                q.pop();
                
                sum += node->val;
                count++;
                
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
            ans.push_back(static_cast<double>(sum)/count);
            sum = 0;
            count = 0;
        }
        
        return ans;
    }
};