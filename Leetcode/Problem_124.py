# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        root_end, root_none = self.maxPathSumDFS(root)
        return max(root_end, root_none)

    def maxPathSumDFS(self, node: TreeNode):
        if not node.left and not node.right:
            return node.val, -float('inf')

        l_end = -float('inf')
        l_none = -float('inf')
        r_end = -float('inf')
        r_none = -float('inf')

        if node.left:
            l_end, l_none = self.maxPathSumDFS(node.left)
        if node.right:
            r_end, r_none = self.maxPathSumDFS(node.right)
        
        node_end = max(l_end + node.val, r_end + node.val, node.val)
        node_none = max(l_end + r_end + node.val, l_end, r_end, l_none, r_none)
        
        return node_end, node_none