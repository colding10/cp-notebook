#
# @lc app=leetcode id=2315 lang=python3
#
# [2315] Count Asterisks
#

# @lc code=start
class Solution:
    def countAsterisks(self, s: str) -> int:
        opened_bar = False
        count = 0
        
        for c in s:
            if c == "|":
                opened_bar = not opened_bar
            if c == "*" and not opened_bar:
                count += 1
        
        return count
# @lc code=end

