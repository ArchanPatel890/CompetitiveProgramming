def IsSum(nums, first, start, end, ans):
    target = 0 - first
    left = start
    right = end
    while left < right:
        cand = nums[left] + nums[right]
        if cand == target:
            ans.append([first, nums[left], nums[right]])
            while left < right and nums[left] == nums[left+1]:
                left += 1
            while left < right and nums[right] == nums[right-1]:
                right -= 1
            left += 1
            right -= 1
        elif cand < target:
            left += 1
        else:
            right -= 1
    

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        nums.sort()
        ans = []
        n = len(nums)
        i = 0
        while i < n-2:
            IsSum(nums, nums[i], i+1, n-1, ans)
            while i < n-2 and nums[i] == nums[i+1]:
                i += 1
            i += 1
        return ans