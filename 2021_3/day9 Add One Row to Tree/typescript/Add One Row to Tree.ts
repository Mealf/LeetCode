/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

 function addOneRow(root: TreeNode | null, v: number, d: number): TreeNode | null {
    if(!root)
        return root;
    
    if(d==1) {
        let new_node: TreeNode = new TreeNode(v);
        new_node.left = root;
        return new_node;
        
    } else if(d==2) {
        let nodeL: TreeNode = root.left;
        let nodeR: TreeNode = root.right;
        
        root.left = new TreeNode(v);
        root.left.left = nodeL;
        
        root.right = new TreeNode(v);
        root.right.right = nodeR;
        
        return root;
    }
    addOneRow(root.left, v, d-1);
    addOneRow(root.right, v, d-1);
    
    return root;
};