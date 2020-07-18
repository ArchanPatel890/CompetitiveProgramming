from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numset = {}
        for num in nums:
            if num not in numset:
                numset[num] = 1
            else:
                numset[num] += 1
        
        maxlength = 0
        for i in nums:
            if numset[i] > 1:
                numset[i] -= 1
            elif i-1 not in numset:
                length = 1
                curr = i
                while curr+1 in numset:
                    length += 1
                    curr += 1
                
                if length > maxlength:
                    maxlength = length

        return maxlength
