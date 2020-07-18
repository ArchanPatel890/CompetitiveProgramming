from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        n = len(nums)
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])
        
        dp = [nums[0], max(nums[0], nums[1])]
        # Pick the first house
        for i in range(2, n-1):
            dp.append(max(dp[i-1], dp[i-2] + nums[i]))
        
        first = dp[-1]

        dp = [nums[1], max(nums[1], nums[2])]
        for i in range(3, n):
            dp.append(max(dp[i-2], dp[i-3] + nums[i]))
        last = dp[-1]
        return max(first, last)
        