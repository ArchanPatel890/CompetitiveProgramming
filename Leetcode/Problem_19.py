# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        start = head
        end = head
        for _ in range(0, n):
            end = end.next
        if not end:
            # N is the length of list, delete head.
            start = head.next
            head.next = None
            return start
        else:
            # Move N+1 spaces.
            end = end.next
        
        while end:
            start = start.next
            end = end.next
        
        # Delete the N-th node.
        start.next = start.next.next
        return head