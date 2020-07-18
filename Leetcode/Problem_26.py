from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0

        idx = 1
        i = idx
        while (i < len(nums)):
            if nums[i] == nums[i-1]:
                i += 1
            else:
                nums[idx] = nums[i]
                idx += 1
                i += 1
        return idx