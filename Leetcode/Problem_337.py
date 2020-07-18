from typing import Tuple

#  Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rob(self, root: TreeNode) -> int:
        if not root:
            return 0
        take, leave = self.rob_dfs(root)
        return max(take, leave)

    def rob_dfs(self, root: TreeNode):
        left_take, left_leave, right_take, right_leave = 0, 0, 0, 0
        if root.left:
            left_take, left_leave = self.rob_dfs(root.left)
        if root.right:
            right_take, right_leave = self.rob_dfs(root.right)
        
        node_take = left_leave + right_leave + root.val
        node_leave = max(left_take, left_leave) + max(right_take, right_leave)
        return node_take, node_leave