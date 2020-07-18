from typing import List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        return self.mergeKListsDivide(0, len(lists)-1, lists)

    def mergeKListsDivide(self, left, right, lists):
        if left == right:
            return lists[left]
        if left < right:
            middle = (left + right) // 2
            left_list = self.mergeKListsDivide(left, middle, lists)
            right_list = self.mergeKListsDivide(middle+1, right, lists)
            return self.MergeTwoLists(left_list, right_list)
        

    def MergeTwoLists(self, one, two):
        if not one:
            return two
        if not two:
            return one
        head = ListNode(0)
        curr = head
        while one and two:
            if one.val < two.val:
                curr.next = one
                one = one.next
            else:
                curr.next = two
                two = two.next
            curr = curr.next
        if not one:
            curr.next = two
        else:
            curr.next = one
        return head.next