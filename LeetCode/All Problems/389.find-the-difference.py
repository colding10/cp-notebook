#
# @lc app=leetcode id=389 lang=python3
#
# [389] Find the Difference
#

# @lc code=start
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        a_counts = {c: s.count(c) for c in set(s)}
        b_counts = {c: t.count(c) for c in set(t)}
        
        for k in a_counts:
            if k not in b_counts:
                return k
            if a_counts[k] != b_counts[k]:
                return k
        for k in b_counts:
            if k not in a_counts:
                return k

# @lc code=end

