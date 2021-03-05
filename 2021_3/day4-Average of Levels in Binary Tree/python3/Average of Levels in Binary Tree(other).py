# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return []
        
        ans = []
        que = deque([root])
        
        while(len(que) > 0):
            count = len(que)
            sum = 0.0
            for _ in range(len(que)):
                node = que.popleft()
                sum += node.val
                if node.left:
                    que.append(node.left) 
                if node.right:
                    que.append(node.right) 
                    
            ans.append(sum/count)
        return ans
                
            
    