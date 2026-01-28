#
# @lc app=leetcode id=125 lang=python3
#
# [125] Valid Palindrome
#

# @lc code=start
class Solution:
    def isPalindrome(self, s: str) -> bool:
        new = []
        for c in s:
            if c.isalnum():
                new.append(c.lower())
        
        return new == new[::-1]
# @lc code=end

