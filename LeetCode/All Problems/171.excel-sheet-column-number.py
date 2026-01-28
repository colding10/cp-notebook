#
# @lc app=leetcode id=171 lang=python3
#
# [171] Excel Sheet Column Number
#

# @lc code=start
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        base = 1
        out = 0
        for c in columnTitle:
            val = ord(c) - 64
            out += val * base
            base *= 26
        
        return out
# @lc code=end

