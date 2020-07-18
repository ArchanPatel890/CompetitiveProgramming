from typing import List

class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        """
        Sorts the array in descending order.
        Find a set starting from the beginning that is more than half of the 
        total sum. If the sum is more than half, the must must be greater 
        than the remaining elements in the array.
        """
        if not nums:
            return nums
        nums.sort()
        nums.reverse()
        n = len(nums)
        target = sum(nums) / 2
        curr_sum = 0
        for i in range(0, n):
            curr_sum += nums[i]
            if curr_sum > target:
                return nums[:i+1]
        return nums

