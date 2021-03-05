# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        ans = list()
        
        q = list()
        q.append(root)
        
        
        while(q):
            n = len(q)
            qc = q.copy()
            q = list()
            sum = 0.0
            for node in qc:
                sum += node.val
                if node.left:
                    q.append(node.left) 
                if node.right:
                    q.append(node.right) 
            ans.append(sum/n)
        return ans
                
            
    