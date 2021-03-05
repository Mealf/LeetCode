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
        vector<double> sum;
        vector<int>  num;
        findSumAndNum(root, 0, sum, num);
        for(int i=0;i<sum.size();i++) {
            sum[i] /= num[i];
        }
        
        return sum;
    }
    
    void findSumAndNum(TreeNode* node, int level, vector<double> &sum, vector<int> &num) {
        if(node == nullptr)
            return;
        
        if(sum.size()<=level)
            sum.push_back(0);
        sum[level] += node->val;
        
        if(num.size()<=level)
            num.push_back(0);
        num[level]++;
        
        findSumAndNum(node->left, level+1, sum, num);
        findSumAndNum(node->right, level+1, sum, num);
        
        return;
    }
};