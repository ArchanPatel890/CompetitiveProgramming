from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        if not root:
            return 0
        q = deque()
        q.append(root)
        max_sum = root.val
        level_max = 1
        level_curr = 1
        while q:
            level_sum = 0
            new_count = 0
            level_count = len(q)
            for _ in range(0, level_count):
                node = q.popleft()
                level_sum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            level_count = new_count
            if level_sum > max_sum:
                max_sum = level_sum
                level_max = level_curr
            
            level_curr += 1
        return level_max