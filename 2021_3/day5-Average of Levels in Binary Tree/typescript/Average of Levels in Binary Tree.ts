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

function averageOfLevels(root: TreeNode | null): number[] {
    if(!root)
        return [];
    
    let ans: number[] = [];
    let queue: TreeNode[] = [root];
    let sum: number = 0;
    let count: number;
    let node: TreeNode;
    while(queue.length > 0){
        count = queue.length;
        sum = 0;
        
        for(let i=0, n=queue.length; i<n; i++) {
            node = queue.shift();
            sum += node.val;
            if(node.left)
                queue.push(node.left);
            if(node.right)
                queue.push(node.right);
        }
        ans.push(sum/count);
    }
    return ans;
    
};