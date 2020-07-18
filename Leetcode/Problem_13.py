class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {'M': 1000,'D': 500 ,'C': 100,'L': 50,'X': 10,'V': 5,'I': 1}
        ans = 0
        n = len(s)-1
        i = 0
        while (i < n):
            curr = roman[s[i]]
            after = roman[s[i+1]]
            if after > curr:
                ans += after - curr
                i += 1
            else:
                ans += curr
            i += 1
        if (i < len(s)):
            ans += roman[s[i]]
        return ans
