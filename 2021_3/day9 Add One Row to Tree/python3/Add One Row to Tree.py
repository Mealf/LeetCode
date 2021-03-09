# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
             
        if d==1:
            new_node = TreeNode(v)
            new_node.left = root
            return new_node
        
        elif d==2:
            nodeL = root.left
            nodeR = root.right
            
            root.left = TreeNode(v)
            root.left.left = nodeL
            
            root.right = TreeNode(v)
            root.right.right = nodeR
            
            return root
        
        if root.left: 
            # function name前要記得加self.
            self.addOneRow(root.left, v, d-1)
        if root.right:
            self.addOneRow(root.right, v, d-1)
        return root
            