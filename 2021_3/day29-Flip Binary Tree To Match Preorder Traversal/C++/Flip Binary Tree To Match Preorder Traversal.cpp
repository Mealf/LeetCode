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
class Solution
{
public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        vector<int> result;
        int index = 0;
        dfs(root, voyage, index, result);
        return result;
    }
    void dfs(TreeNode *node, vector<int> v, int &index, vector<int> &result)
    {
        if (!node)
            return;
        if (!result.empty() && result.front() == -1)
            return;

        if (node->val == v[index++])
        {
            if (node->left && node->right && node->right->val == v[index])
            {
                result.push_back(node->val);
                swap(node->right, node->left);
            }
            
            dfs(node->left, v, index, result);
            dfs(node->right, v, index, result);
        }
        else
        {
            result = vector<int>{-1};
        }
    }
};